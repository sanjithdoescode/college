# Universal Shift Register

## Simple definition
A universal shift register is a sequential digital circuit that, based on select inputs, can hold its current value, shift left, shift right, or load new data in parallel.

## Block diagram
![4‑bit universal shift register](https://upload.wikimedia.org/wikipedia/commons/thumb/8/89/4-bit_universal_shift_register.svg/512px-4-bit_universal_shift_register.svg.png)
Source: [Wikipedia — "Shift register"](https://en.wikipedia.org/wiki/Shift_register)

## Operating modes (one‑liners)
- Parallel Load: load all bits at once from parallel inputs `D3..D0`.
- Shift Left: shift toward MSB; new bit enters at LSB serial input `SLin`.
- Shift Right: shift toward LSB; new bit enters at MSB serial input `SRin`.
- Hold: preserve the current register contents.

## Control truth table (mode select)
| S1 | S0 | Operation     |
|----|----|---------------|
| 0  | 0  | Hold          |
| 0  | 1  | Shift Right   |
| 1  | 0  | Shift Left    |
| 1  | 1  | Parallel Load |

## Next‑state truth table (4‑bit register)
Symbols: `Qk` = current bit, `Qk(next)` = next state after clock, `Dk` = parallel input, `SRin`/`SLin` = serial inputs for right/left shifts.

| Operation     | S1 | S0 | Q3(next) | Q2(next) | Q1(next) | Q0(next) |
|---------------|----|----|----------|----------|----------|----------|
| Hold          | 0  | 0  | Q3       | Q2       | Q1       | Q0       |
| Shift Right   | 0  | 1  | SRin     | Q3       | Q2       | Q1       |
| Shift Left    | 1  | 0  | Q2       | Q1       | Q0       | SLin     |
| Parallel Load | 1  | 1  | D3       | D2       | D1       | D0       |



## simulating every scenario fyi (4‑bit)

Legend: `Q3 Q2 Q1 Q0` = current state; `Q3' Q2' Q1' Q0'` = next state after the clock.

### Hold (S1=0, S0=0)
| S1 | S0 | Q3 | Q2 | Q1 | Q0 | Q3' | Q2' | Q1' | Q0' |
|----|----|----|----|----|----|-----|-----|-----|-----|
| 0  | 0  | 0  | 0  | 0  | 0  | 0   | 0   | 0   | 0   |
| 0  | 0  | 0  | 0  | 0  | 1  | 0   | 0   | 0   | 1   |
| 0  | 0  | 0  | 0  | 1  | 0  | 0   | 0   | 1   | 0   |
| 0  | 0  | 0  | 0  | 1  | 1  | 0   | 0   | 1   | 1   |
| 0  | 0  | 0  | 1  | 0  | 0  | 0   | 1   | 0   | 0   |
| 0  | 0  | 0  | 1  | 0  | 1  | 0   | 1   | 0   | 1   |
| 0  | 0  | 0  | 1  | 1  | 0  | 0   | 1   | 1   | 0   |
| 0  | 0  | 0  | 1  | 1  | 1  | 0   | 1   | 1   | 1   |
| 0  | 0  | 1  | 0  | 0  | 0  | 1   | 0   | 0   | 0   |
| 0  | 0  | 1  | 0  | 0  | 1  | 1   | 0   | 0   | 1   |
| 0  | 0  | 1  | 0  | 1  | 0  | 1   | 0   | 1   | 0   |
| 0  | 0  | 1  | 0  | 1  | 1  | 1   | 0   | 1   | 1   |
| 0  | 0  | 1  | 1  | 0  | 0  | 1   | 1   | 0   | 0   |
| 0  | 0  | 1  | 1  | 0  | 1  | 1   | 1   | 0   | 1   |
| 0  | 0  | 1  | 1  | 1  | 0  | 1   | 1   | 1   | 0   |
| 0  | 0  | 1  | 1  | 1  | 1  | 1   | 1   | 1   | 1   |

### Shift Right (S1=0, S0=1) — next: Q3'=SRin, Q2'=Q3, Q1'=Q2, Q0'=Q1
| S1 | S0 | SRin | Q3 | Q2 | Q1 | Q0 | Q3' | Q2' | Q1' | Q0' |
|----|----|------|----|----|----|----|-----|-----|-----|-----|
| 0  | 1  | 0    | 0  | 0  | 0  | 0  | 0   | 0   | 0   | 0   |
| 0  | 1  | 0    | 0  | 0  | 0  | 1  | 0   | 0   | 0   | 0   |
| 0  | 1  | 0    | 0  | 0  | 1  | 0  | 0   | 0   | 0   | 1   |
| 0  | 1  | 0    | 0  | 0  | 1  | 1  | 0   | 0   | 0   | 1   |
| 0  | 1  | 0    | 0  | 1  | 0  | 0  | 0   | 0   | 1   | 0   |
| 0  | 1  | 0    | 0  | 1  | 0  | 1  | 0   | 0   | 1   | 0   |
| 0  | 1  | 0    | 0  | 1  | 1  | 0  | 0   | 0   | 1   | 1   |
| 0  | 1  | 0    | 0  | 1  | 1  | 1  | 0   | 0   | 1   | 1   |
| 0  | 1  | 0    | 1  | 0  | 0  | 0  | 0   | 1   | 0   | 0   |
| 0  | 1  | 0    | 1  | 0  | 0  | 1  | 0   | 1   | 0   | 0   |
| 0  | 1  | 0    | 1  | 0  | 1  | 0  | 0   | 1   | 0   | 1   |
| 0  | 1  | 0    | 1  | 0  | 1  | 1  | 0   | 1   | 0   | 1   |
| 0  | 1  | 0    | 1  | 1  | 0  | 0  | 0   | 1   | 1   | 0   |
| 0  | 1  | 0    | 1  | 1  | 0  | 1  | 0   | 1   | 1   | 0   |
| 0  | 1  | 0    | 1  | 1  | 1  | 0  | 0   | 1   | 1   | 1   |
| 0  | 1  | 0    | 1  | 1  | 1  | 1  | 0   | 1   | 1   | 1   |
| 0  | 1  | 1    | 0  | 0  | 0  | 0  | 1   | 0   | 0   | 0   |
| 0  | 1  | 1    | 0  | 0  | 0  | 1  | 1   | 0   | 0   | 0   |
| 0  | 1  | 1    | 0  | 0  | 1  | 0  | 1   | 0   | 0   | 1   |
| 0  | 1  | 1    | 0  | 0  | 1  | 1  | 1   | 0   | 0   | 1   |
| 0  | 1  | 1    | 0  | 1  | 0  | 0  | 1   | 0   | 1   | 0   |
| 0  | 1  | 1    | 0  | 1  | 0  | 1  | 1   | 0   | 1   | 0   |
| 0  | 1  | 1    | 0  | 1  | 1  | 0  | 1   | 0   | 1   | 1   |
| 0  | 1  | 1    | 0  | 1  | 1  | 1  | 1   | 0   | 1   | 1   |
| 0  | 1  | 1    | 1  | 0  | 0  | 0  | 1   | 1   | 0   | 0   |
| 0  | 1  | 1    | 1  | 0  | 0  | 1  | 1   | 1   | 0   | 0   |
| 0  | 1  | 1    | 1  | 0  | 1  | 0  | 1   | 1   | 0   | 1   |
| 0  | 1  | 1    | 1  | 0  | 1  | 1  | 1   | 1   | 0   | 1   |
| 0  | 1  | 1    | 1  | 1  | 0  | 0  | 1   | 1   | 1   | 0   |
| 0  | 1  | 1    | 1  | 1  | 0  | 1  | 1   | 1   | 1   | 0   |
| 0  | 1  | 1    | 1  | 1  | 1  | 0  | 1   | 1   | 1   | 1   |
| 0  | 1  | 1    | 1  | 1  | 1  | 1  | 1   | 1   | 1   | 1   |

### Shift Left (S1=1, S0=0) — next: Q3'=Q2, Q2'=Q1, Q1'=Q0, Q0'=SLin
| S1 | S0 | SLin | Q3 | Q2 | Q1 | Q0 | Q3' | Q2' | Q1' | Q0' |
|----|----|------|----|----|----|----|-----|-----|-----|-----|
| 1  | 0  | 0    | 0  | 0  | 0  | 0  | 0   | 0   | 0   | 0   |
| 1  | 0  | 0    | 0  | 0  | 0  | 1  | 0   | 0   | 1   | 0   |
| 1  | 0  | 0    | 0  | 0  | 1  | 0  | 0   | 1   | 0   | 0   |
| 1  | 0  | 0    | 0  | 0  | 1  | 1  | 0   | 1   | 1   | 0   |
| 1  | 0  | 0    | 0  | 1  | 0  | 0  | 1   | 0   | 0   | 0   |
| 1  | 0  | 0    | 0  | 1  | 0  | 1  | 1   | 0   | 1   | 0   |
| 1  | 0  | 0    | 0  | 1  | 1  | 0  | 1   | 1   | 0   | 0   |
| 1  | 0  | 0    | 0  | 1  | 1  | 1  | 1   | 1   | 1   | 0   |
| 1  | 0  | 0    | 1  | 0  | 0  | 0  | 0   | 0   | 0   | 0   |
| 1  | 0  | 0    | 1  | 0  | 0  | 1  | 0   | 0   | 1   | 0   |
| 1  | 0  | 0    | 1  | 0  | 1  | 0  | 0   | 1   | 0   | 0   |
| 1  | 0  | 0    | 1  | 0  | 1  | 1  | 0   | 1   | 1   | 0   |
| 1  | 0  | 0    | 1  | 1  | 0  | 0  | 1   | 0   | 0   | 0   |
| 1  | 0  | 0    | 1  | 1  | 0  | 1  | 1   | 0   | 1   | 0   |
| 1  | 0  | 0    | 1  | 1  | 1  | 0  | 1   | 1   | 0   | 0   |
| 1  | 0  | 0    | 1  | 1  | 1  | 1  | 1   | 1   | 1   | 0   |
| 1  | 0  | 1    | 0  | 0  | 0  | 0  | 0   | 0   | 0   | 1   |
| 1  | 0  | 1    | 0  | 0  | 0  | 1  | 0   | 0   | 1   | 1   |
| 1  | 0  | 1    | 0  | 0  | 1  | 0  | 0   | 1   | 0   | 1   |
| 1  | 0  | 1    | 0  | 0  | 1  | 1  | 0   | 1   | 1   | 1   |
| 1  | 0  | 1    | 0  | 1  | 0  | 0  | 1   | 0   | 0   | 1   |
| 1  | 0  | 1    | 0  | 1  | 0  | 1  | 1   | 0   | 1   | 1   |
| 1  | 0  | 1    | 0  | 1  | 1  | 0  | 1   | 1   | 0   | 1   |
| 1  | 0  | 1    | 0  | 1  | 1  | 1  | 1   | 1   | 1   | 1   |
| 1  | 0  | 1    | 1  | 0  | 0  | 0  | 0   | 0   | 0   | 1   |
| 1  | 0  | 1    | 1  | 0  | 0  | 1  | 0   | 0   | 1   | 1   |
| 1  | 0  | 1    | 1  | 0  | 1  | 0  | 0   | 1   | 0   | 1   |
| 1  | 0  | 1    | 1  | 0  | 1  | 1  | 0   | 1   | 1   | 1   |
| 1  | 0  | 1    | 1  | 1  | 0  | 0  | 1   | 0   | 0   | 1   |
| 1  | 0  | 1    | 1  | 1  | 0  | 1  | 1   | 0   | 1   | 1   |
| 1  | 0  | 1    | 1  | 1  | 1  | 0  | 1   | 1   | 0   | 1   |
| 1  | 0  | 1    | 1  | 1  | 1  | 1  | 1   | 1   | 1   | 1   |

### Parallel Load (S1=1, S0=1) — next: Q' = D
| S1 | S0 | D3 | D2 | D1 | D0 | Q3' | Q2' | Q1' | Q0' |
|----|----|----|----|----|----|-----|-----|-----|-----|
| 1  | 1  | 0  | 0  | 0  | 0  | 0   | 0   | 0   | 0   |
| 1  | 1  | 0  | 0  | 0  | 1  | 0   | 0   | 0   | 1   |
| 1  | 1  | 0  | 0  | 1  | 0  | 0   | 0   | 1   | 0   |
| 1  | 1  | 0  | 0  | 1  | 1  | 0   | 0   | 1   | 1   |
| 1  | 1  | 0  | 1  | 0  | 0  | 0   | 1   | 0   | 0   |
| 1  | 1  | 0  | 1  | 0  | 1  | 0   | 1   | 0   | 1   |
| 1  | 1  | 0  | 1  | 1  | 0  | 0   | 1   | 1   | 0   |
| 1  | 1  | 0  | 1  | 1  | 1  | 0   | 1   | 1   | 1   |
| 1  | 1  | 1  | 0  | 0  | 0  | 1   | 0   | 0   | 0   |
| 1  | 1  | 1  | 0  | 0  | 1  | 1   | 0   | 0   | 1   |
| 1  | 1  | 1  | 0  | 1  | 0  | 1   | 0   | 1   | 0   |
| 1  | 1  | 1  | 0  | 1  | 1  | 1   | 0   | 1   | 1   |
| 1  | 1  | 1  | 1  | 0  | 0  | 1   | 1   | 0   | 0   |
| 1  | 1  | 1  | 1  | 0  | 1  | 1   | 1   | 0   | 1   |
| 1  | 1  | 1  | 1  | 1  | 0  | 1   | 1   | 1   | 0   |
| 1  | 1  | 1  | 1  | 1  | 1  | 1   | 1   | 1   | 1   |

## Applications
- Data routing: steer data between serial lines and parallel buses (or between buses) by choosing left/right shift; use Hold to pause and Parallel Load to stage words.
- Arithmetic shifts: perform signed shifts by feeding `SRin = Q3` for arithmetic right shift (sign-extend) or left shift to multiply by 2; clamp/mask externally if needed.
- Serial/parallel conversion: act as SIPO (shift in serial, read out parallel) and PISO (parallel load, shift out serial) for peripheral interfacing.
