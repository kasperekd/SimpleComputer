# Simple Computer Emulator

## Project Description

The Simple Computer Emulator project is a basic simulation of a computer's functionality. It includes the following components:

1. **Input/Output Device**
2. **Interrupt Handler**
3. **RAM (Random Access Memory)**
4. **L1 Cache**
5. **Memory Controller**
6. **Control Unit**
7. **Registers**:
   - Accumulator
   - Program Counter
   - Flags Register
   - Idle Cycle Counter

The project also includes translators for the simpleAssembler (SA) and simpleBasic (SB) languages, allowing users to write small programs in these languages, translate them into Simple Computer processor commands, and load them into the Simple Computer. Additionally, SB supports reverse Polish notation.

## Project Structure

- `./console` - Source code and executable files for the emulator
- `./examples` - Example programs in simpleAssembler and simpleBasic
- `./include` - Header files
- Static libraries:
  - `./myBigChars`
  - `./myCache`
  - `./myReadkey`
  - `./mySimpleComputer`
  - `./myTerm`
- `./translators` - Source code and executable files for the simpleAssembler and simpleBasic translators

## Requirements

To build and run the project, you need a C compiler that supports the C99 standard or higher.

## Building the Project

To build the project, run the following command in the root directory:

```sh
make
```

## Running the Emulator

After a successful build, you can run the Simple Computer using the following command:

```sh
./console/build/console
```

## Using the Translators

### simpleAssembler (SA)

To translate a program written in simpleAssembler, follow these steps:

1. Navigate to the `translators/build` directory:
    ```sh
    cd translators/build
    ```
2. Run the simpleAssembler translator:
    ```sh
    ./sat ../examples/program.sa program
    ```

### simpleBasic (SB)

To translate a program written in simpleBasic, follow these steps:

1. Navigate to the `translators/build` directory:
    ```sh
    cd translators/build
    ```
2. Run the simpleBasic translator:
    ```sh
    ./sbt ../examples/program.sb program 
    ```

## Examples

### Example Program in simpleAssembler

```asm
00 LOAD 10
01 ADD 20
02 STORE 30
03 HALT 01
```

### Example Program in simpleBasic

```basic
10 LET A = 10
20 LET B = 20
30 LET C = A + B
40 PRINT C
50 END
```

### Example Program in simpleBasic Using Reverse Polish Notation

```basic
10 LET A = 10
20 LET B = 20
30 LET C = A + B * A
40 PRINT C
50 END
```

## Components

### Input/Output Device

Implements basic input and output operations.

### Interrupt Handler

Handles hardware and software interrupts.

### RAM (Random Access Memory)

Emulates the computer's main memory.

### L1 Cache

Implements a first-level cache to speed up data access.

### Memory Controller

Manages access to the RAM and cache.

### Control Unit

Organizes command execution and manages all computer components.

### Registers

- **Accumulator**: The main register for performing arithmetic and logic operations.
- **Program Counter**: Points to the current command being executed.
- **Flags Register**: Contains processor status flags.
- **Idle Cycle Counter**: Tracks the number of cycles the processor is idle.
