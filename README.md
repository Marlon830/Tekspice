# NanoTekspice

> Made by **Marlon PEGAHI** and **Alexandre BRET**

A digital circuit simulator written in C++20. NanoTekspice parses `.nts` circuit description files and lets you simulate logic circuits interactively.

---

## Features

- Tristate logic: `1` (True), `0` (False), `U` (Undefined)
- Basic logic gates: AND, OR, XOR, NOT
- Special components: clock, flip-flop, 4514 decoder, logger
- Complex IC chips: NOR, NAND, 4001, 4011, 4030, 4069, 4071, 4081, 4008, 4013, full adder
- Interactive simulation with tick-by-tick control or continuous loop mode
- `.nts` circuit description file format

---

## Requirements

- g++ with C++20 support
- GNU Make
- [Criterion](https://github.com/Snaipe/Criterion) (for unit tests only)

---

## Build

```bash
make          # Build the nanotekspice binary
make re       # Full rebuild
make fclean   # Remove binary and object files
```

---

## Usage

```bash
./nanotekspice <circuit.nts>
```

Once running, the REPL accepts the following commands:

| Command        | Description                                      |
|----------------|--------------------------------------------------|
| `display`      | Print the current tick and all input/output values |
| `simulate`     | Advance the simulation by one tick               |
| `loop`         | Run continuously until `Ctrl+C`                  |
| `name=value`   | Set an input to `1`, `0`, or `U`                 |
| `exit`         | Quit the simulator                               |

### Example session

```
$ ./nanotekspice test.nts
> in_1=1
> in_2=1
> simulate
> display
tick: 1
input(s):
  in_1: 1
  in_2: 1
  in_3: U
output(s):
  out_1: 1
> exit
```

---

## Circuit File Format (.nts)

A `.nts` file has two mandatory sections:

```
.chipsets:
<type> <name>
...

.links:
<component1>:<pin> <component2>:<pin>
...
```

- Lines starting with `#` are comments.
- Pins are 1-indexed.

### Example — AND gate

```
.chipsets:
input in_a
input in_b
and  gate_and
output out

.links:
in_a:1  gate_and:1
in_b:1  gate_and:2
gate_and:3  out:1
```

### Available component types

| Type         | Description                        |
|--------------|------------------------------------|
| `input`      | User-controlled input              |
| `output`     | Output probe                       |
| `clock`      | Toggles on each simulate           |
| `true`       | Constant 1                         |
| `false`      | Constant 0                         |
| `logger`     | Logs signal values to stdout       |
| `and`        | 2-input AND gate                   |
| `or`         | 2-input OR gate                    |
| `xor`        | 2-input XOR gate                   |
| `not`        | 1-input NOT gate                   |
| `nor`        | 2-input NOR gate                   |
| `nand`       | 2-input NAND gate                  |
| `flipflop`   | SR flip-flop                       |
| `4001`       | Quad NOR (CD4001)                  |
| `4011`       | Quad NAND (CD4011)                 |
| `4030`       | Quad XOR (CD4030)                  |
| `4069`       | Hex NOT (CD4069)                   |
| `4071`       | Quad OR (CD4071)                   |
| `4081`       | Quad AND (CD4081)                  |
| `4008`       | 4-bit full adder (CD4008)          |
| `4013`       | Dual D flip-flop (CD4013)          |
| `4514`       | 4-to-16 decoder (CD4514)           |
| `full_adder` | 1-bit full adder                   |

---

## Tests

```bash
make tests_run          # Run all unit tests
make gcovr_tests_run    # Run tests with code coverage report
```

---

## Project Structure

```
src/
├── Interface/          # IComponent pure virtual interface
├── Abstract/           # AComponent base implementation
├── Components/         # Basic gates, inputs, outputs, circuit container
├── AdvancedComponents/ # Flip-flop, 4514, logger
├── Parser/             # .nts file parser
├── Simulation/         # Global simulation state
└── Main.cpp            # Entry point and REPL
tests/                  # Criterion unit tests
```

---

## Exit Codes

| Code | Meaning          |
|------|------------------|
| `0`  | Success          |
| `84` | Invalid argument or file error |
