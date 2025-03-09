# Turing Machine (TM) for Binary Addition

## Overview
This project implements a **Turing Machine (TM)** in C++ that processes binary numbers for addition. The TM reads a binary string where two numbers are separated by an `a` and computes their sum.

## Features
- Implements **state transitions** using an enumeration.
- Uses a **tape head** to traverse and modify the binary string.
- Determines the **sum** of two binary numbers.
- Handles user input dynamically.

## How It Works
1. **Initialize the Turing Machine**: A `TM` object is created.
2. **Process Input**:
   - The user enters a binary string with an `a` separator.
   - The machine scans and modifies the tape based on predefined state transitions.
3. **State Transitions**:
   - Moves between predefined states (`dotI, dotJ, dotK, dotL, dotM, dotN, dotO, dotP, retT, retF`).
   - The machine performs binary addition using state changes and tape modifications.
4. **Output Result**: Displays the **binary sum** of the two input numbers.

## Installation
Ensure you have a C++ compiler installed. You can use **GCC** or **MSVC**.

## Compilation & Execution
### Using g++
```bash
g++ -o turing_machine tm.cpp
./turing_machine
```
### Using MSVC (Windows)
```powershell
cl tm.cpp
tm.exe
```

## Example Output
```
Enter a binary number to add. Place an 'a' in the middle of the binary numbers to add: 1101a101
The binary sum of your two numbers is: 10110
```

## License
This project is open-source and free to use.
