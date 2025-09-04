from dataclasses import dataclass
from typing import Optional, Tuple
import time
import os
import sys # unused so deltete it

# ansi color codes butiful colors
class Colors:
    RESET = '\033[0m'
    BOLD = '\033[1m'
    RED = '\033[91m'
    GREEN = '\033[92m'
    YELLOW = '\033[93m'
    BLUE = '\033[94m'
    MAGENTA = '\033[95m'
    CYAN = '\033[96m'
    WHITE = '\033[97m'
    BG_RED = '\033[41m'
    BG_GREEN = '\033[42m'
    BG_YELLOW = '\033[43m'
    BG_BLUE = '\033[44m'

MODE_HOLD = (0, 0)
MODE_SHIFT_L = (0, 1)
MODE_SHIFT_R = (1, 0)
MODE_LOAD = (1, 1)

MODE_COLORS = {
    MODE_HOLD: Colors.BLUE,
    MODE_SHIFT_L: Colors.GREEN,
    MODE_SHIFT_R: Colors.YELLOW,
    MODE_LOAD: Colors.MAGENTA
}

MODE_NAME = {
    MODE_HOLD: "HOLD",
    MODE_SHIFT_L: "SHIFT_LEFT",
    MODE_SHIFT_R: "SHIFT_RIGHT",
    MODE_LOAD: "PARALLEL_LOAD",
}

@dataclass
class Step:
    s1: int
    s0: int
    dsl: Optional[int] = None  # serial-in for shift-left
    dsr: Optional[int] = None  # serial-in for shift-right
    din: Optional[int] = None  # parallel load data as integer
    note: str = ""

class UniversalShiftRegister:
    def __init__(self, n_bits: int):
        self.n = n_bits
        self.q = [0] * n_bits  # q=Q0 (LSB), q[n-1]=MSB

    def as_int(self) -> int:
        val = 0
        for i, b in enumerate(self.q):
            val |= (b & 1) << i
        return val

    def from_int(self, value: int):
        for i in range(self.n):
            self.q[i] = (value >> i) & 1

    def clock(self, s1: int, s0: int, dsl: Optional[int], dsr: Optional[int], din: Optional[int]) -> Tuple[int, int]:
        q_before = self.as_int()
        # for logging: bits that would shift out
        right_out = self.q[0]
        left_out = self.q[self.n-1]
        if (s1, s0) == MODE_HOLD:
            pass
        elif (s1, s0) == MODE_SHIFT_L:
            if dsl is None:
                raise ValueError("DSL required for SHIFT_LEFT")
            for i in range(self.n-1, 0, -1):
                self.q[i] = self.q[i-1]
            self.q[0] = dsl
        elif (s1, s0) == MODE_SHIFT_R:
            if dsr is None:
                raise ValueError("DSR required for SHIFT_RIGHT")
            for i in range(0, self.n-1):
                self.q[i] = self.q[i+1]
            self.q[self.n-1] = dsr
        elif (s1, s0) == MODE_LOAD:
            if din is None:
                raise ValueError("DIN required for PARALLEL_LOAD")
            self.from_int(din)
        else:
            raise ValueError("Invalid mode")
        q_after = self.as_int()
        return q_before, q_after, right_out, left_out

    def draw_register(self, highlight_bit=None, title=""):
        """Draw ASCII art representation of the shift register"""
        print(f"\n{Colors.BOLD}{Colors.CYAN}{'='*60}{Colors.RESET}")
        if title:
            print(f"{Colors.BOLD}{Colors.CYAN}║{Colors.RESET} {Colors.BOLD}{Colors.WHITE}{title.center(56)}{Colors.RESET} {Colors.BOLD}{Colors.CYAN}║{Colors.RESET}")
        print(f"{Colors.BOLD}{Colors.CYAN}{'='*60}{Colors.RESET}")

        # Control signals
        print(f"{Colors.BOLD}Control Signals:{Colors.RESET}")
        print(f"  S1: {'HIGH' if self.q else 'LOW'}  S0: {'HIGH' if self.q else 'LOW'}")

        # Register visualization
        print(f"\n{Colors.BOLD}Shift Register State:{Colors.RESET}")
        print("     MSB                                               LSB")
        print("      ▼                                                ▼")

        # Top border
        register_line = "   ┌─"
        for i in range(self.n):
            register_line += "────┬─" if i < self.n-1 else "────┐"
        print(register_line)

        # Bit values
        bit_line = "   │ "
        for i in range(self.n-1, -1, -1):  # MSB to LSB
            bit_color = Colors.GREEN if self.q[i] else Colors.RED
            if highlight_bit is not None and i == highlight_bit:
                bit_color = Colors.YELLOW + Colors.BOLD
            bit_line += f"{bit_color}{self.q[i]}{Colors.RESET} │ "
        print(bit_line)

        # Bottom border
        register_line = "   └─"
        for i in range(self.n):
            register_line += "────┴─" if i < self.n-1 else "────┘"
        print(register_line)

        # Bit positions
        pos_line = "     "
        for i in range(self.n-1, -1, -1):
            pos_line += f" Q{i}  "
        print(f"{Colors.CYAN}{pos_line}{Colors.RESET}")

        # Current value
        print(f"\n{Colors.BOLD}Current Value:{Colors.RESET}")
        print(f"  Decimal: {Colors.GREEN}{self.as_int()}{Colors.RESET}")
        print(f"  Hexadecimal: {Colors.GREEN}0x{self.as_int():02X}{Colors.RESET}")
        print(f"  Binary: {Colors.GREEN}{''.join(map(str, self.q[::-1]))}{Colors.RESET}")

def clear_screen():
    """Clear the terminal screen"""
    os.system('cls' if os.name == 'nt' else 'clear')

def print_table_header():
    """Print formatted table header"""
    print(f"\n{Colors.BOLD}{Colors.WHITE}{'─'*95}{Colors.RESET}")
    print(f"{Colors.BOLD}{Colors.WHITE}│ {'Cycle':<5} │ {'S1':<2} │ {'S0':<2} │ {'Mode':<15} │ {'DSL':<3} │ {'DSR':<3} │ {'DIN':<6} │ {'Q Before':<8} │ {'Q After':<7} │ {'Note':<20} │{Colors.RESET}")
    print(f"{Colors.BOLD}{Colors.WHITE}{'─'*95}{Colors.RESET}")

def print_table_row(cycle, s1, s0, mode, dsl, dsr, din, q_before, q_after, note):
    """Print formatted table row"""
    mode_color = MODE_COLORS.get((s1, s0), Colors.WHITE)
    dsl_str = f"{Colors.GREEN}{dsl}{Colors.RESET}" if dsl is not None else "─"
    dsr_str = f"{Colors.GREEN}{dsr}{Colors.RESET}" if dsr is not None else "─"
    din_str = f"{Colors.GREEN}{hex(din)}{Colors.RESET}" if din is not None else "─"

    print(f"│ {Colors.CYAN}{cycle:<5}{Colors.RESET} │ {Colors.YELLOW}{s1:<2}{Colors.RESET} │ {Colors.YELLOW}{s0:<2}{Colors.RESET} │ {mode_color}{mode:<15}{Colors.RESET} │ {dsl_str:<3} │ {dsr_str:<3} │ {din_str:<6} │ {Colors.BLUE}{hex(q_before):<8}{Colors.RESET} │ {Colors.GREEN}{hex(q_after):<7}{Colors.RESET} │ {Colors.MAGENTA}{note:<20}{Colors.RESET} │")

def run_visual_demo():
    """Run an enhanced visual demonstration"""
    clear_screen()
    print(f"{Colors.BOLD}{Colors.MAGENTA}{' UNIVERSAL SHIT REGISTER VISUAL DEMONSTRATION '.center(80)}{Colors.RESET}")
    print(f"{Colors.CYAN}{'Demonstrating 8-bit Universal Shift Register Operations'.center(80)}{Colors.RESET}")

    us = UniversalShiftRegister(8)

    # Enhanced demo steps
    steps = [
        Step(1,1, din=0b10110011, note="Load 0xB3"),
        Step(1,0, dsr=1, note="Shift right + 1"),
        Step(1,0, dsr=1, note="Shift right + 1"),
        Step(0,0, note="Hold state"),
        Step(0,1, dsl=0, note="Shift left + 0"),
        Step(0,1, dsl=0, note="Shift left + 0"),
        Step(1,1, din=0x3C, note="Load 0x3C"),
        Step(1,0, dsr=0, note="Shift right + 0"),
        Step(0,1, dsl=1, note="Shift left + 1"),
    ]

    print_table_header()

    for cycle, st in enumerate(steps, 1):
        # Show register state before operation
        us.draw_register(title=f"Cycle {cycle}: Before {MODE_NAME[(st.s1, st.s0)]}")

        qb, qa, right_out, left_out = us.clock(st.s1, st.s0, st.dsl, st.dsr, st.din)

        print_table_row(
            cycle, st.s1, st.s0, MODE_NAME[(st.s1, st.s0)],
            st.dsl, st.dsr, st.din, qb, qa, st.note
        )

        # Show register state after operation
        us.draw_register(title=f"Cycle {cycle}: After {MODE_NAME[(st.s1, st.s0)]}")

        # Add animation delay
        time.sleep(1.5)

        # Separator between cycles
        print(f"\n{Colors.BOLD}{Colors.CYAN}{'─'*95}{Colors.RESET}")
        input(f"{Colors.YELLOW}Press Enter to continue to next cycle...{Colors.RESET}")
        clear_screen()

    print(f"\n{Colors.BOLD}{Colors.GREEN}{'🎉 DEMONSTRATION COMPLETE! 🎉'.center(80)}{Colors.RESET}")
    print(f"{Colors.CYAN}{'The universal shift register has demonstrated all four modes:'.center(80)}{Colors.RESET}")
    print(f"{Colors.WHITE}{'• Parallel Load • Right Shift • Left Shift • Hold'.center(80)}{Colors.RESET}")

def run_interactive_demo():
    """Run an interactive demonstration"""
    clear_screen()
    print(f"{Colors.BOLD}{Colors.MAGENTA}{'🎮 INTERACTIVE UNIVERSAL SHIFT REGISTER 🎮'.center(80)}{Colors.RESET}")

    # Get user input for register size
    while True:
        try:
            n_bits = int(input(f"{Colors.CYAN}Enter number of bits (4-16): {Colors.RESET}"))
            if 4 <= n_bits <= 16:
                break
            print(f"{Colors.RED}Please enter a number between 4 and 16.{Colors.RESET}")
        except ValueError:
            print(f"{Colors.RED}Please enter a valid number.{Colors.RESET}")

    us = UniversalShiftRegister(n_bits)
    us.draw_register(title="Initial State")

    while True:
        print(f"\n{Colors.BOLD}Available Operations:{Colors.RESET}")
        print(f"  {Colors.MAGENTA}1.{Colors.RESET} Parallel Load")
        print(f"  {Colors.GREEN}2.{Colors.RESET} Shift Left")
        print(f"  {Colors.YELLOW}3.{Colors.RESET} Shift Right")
        print(f"  {Colors.BLUE}4.{Colors.RESET} Hold")
        print(f"  {Colors.RED}5.{Colors.RESET} Exit")

        try:
            choice = int(input(f"{Colors.CYAN}Choose operation (1-5): {Colors.RESET}"))
        except ValueError:
            print(f"{Colors.RED}Please enter a valid number.{Colors.RESET}")
            continue

        if choice == 5:
            print(f"{Colors.GREEN}Goodbye! 👋{Colors.RESET}")
            break

        if choice == 1:  # Parallel Load
            try:
                value = int(input(f"{Colors.CYAN}Enter value to load (0-{2**n_bits-1}): {Colors.RESET}"), 0)
                if 0 <= value < 2**n_bits:
                    qb, qa, _, _ = us.clock(1, 1, None, None, value)
                    us.draw_register(title=f"Loaded 0x{value:02X}")
                else:
                    print(f"{Colors.RED}Value out of range!{Colors.RESET}")
            except ValueError:
                print(f"{Colors.RED}Please enter a valid number.{Colors.RESET}")

        elif choice == 2:  # Shift Left
            try:
                dsl = int(input(f"{Colors.CYAN}Enter serial input (0 or 1): {Colors.RESET}"))
                if dsl in [0, 1]:
                    qb, qa, _, _ = us.clock(0, 1, dsl, None, None)
                    us.draw_register(title=f"Shifted Left (DSL={dsl})")
                else:
                    print(f"{Colors.RED}Please enter 0 or 1.{Colors.RESET}")
            except ValueError:
                print(f"{Colors.RED}Please enter a valid number.{Colors.RESET}")

        elif choice == 3:  # Shift Right
            try:
                dsr = int(input(f"{Colors.CYAN}Enter serial input (0 or 1): {Colors.RESET}"))
                if dsr in [0, 1]:
                    qb, qa, _, _ = us.clock(1, 0, None, dsr, None)
                    us.draw_register(title=f"Shifted Right (DSR={dsr})")
                else:
                    print(f"{Colors.RED}Please enter 0 or 1.{Colors.RESET}")
            except ValueError:
                print(f"{Colors.RED}Please enter a valid number.{Colors.RESET}")

        elif choice == 4:  # Hold
            qb, qa, _, _ = us.clock(0, 0, None, None, None)
            us.draw_register(title="Holding State")

        else:
            print(f"{Colors.RED}Invalid choice! Please select 1-5.{Colors.RESET}")

def main():
    """Main menu"""
    while True:
        clear_screen()
        print(f"{Colors.BOLD}{Colors.MAGENTA}{'🎯 UNIVERSAL SHIT REGISTER DEMO MENU 🎯'.center(80)}{Colors.RESET}")
        print(f"{Colors.CYAN}{'Choose your demonstration mode:'.center(80)}{Colors.RESET}")
        print()
        print(f"  {Colors.GREEN}1.{Colors.RESET} Automated Visual Demo")
        print(f"  {Colors.BLUE}2.{Colors.RESET} Interactive Mode")
        print(f"  {Colors.RED}3.{Colors.RESET} Exit")
        print()

        try:
            choice = int(input(f"{Colors.CYAN}Enter your choice (1-3): {Colors.RESET}"))
        except ValueError:
            print(f"{Colors.RED}Please enter a valid number.{Colors.RESET}")
            time.sleep(1)
            continue

        if choice == 1:
            run_visual_demo()
            input(f"{Colors.YELLOW}Press Enter to return to menu...{Colors.RESET}")
        elif choice == 2:
            run_interactive_demo()
        elif choice == 3:
            print(f"{Colors.GREEN}Goodbye! 👋{Colors.RESET}")
            break
        else:
            print(f"{Colors.RED}Invalid choice! Please select 1-3.{Colors.RESET}")
            time.sleep(1)

if __name__ == "__main__":
    main()
