# Premium Multi-Task Calculator (C Language)

A robust, menu-driven command-line application designed to handle a wide range of mathematical tasks. This project demonstrates proficiency in C programming, including complex logic, modular function design, and user input validation.

## 🚀 Features

### 1. Standard Arithmetic
*   **Basic operations:** Addition, Subtraction, Multiplication, and Division (with zero-check).
*   **Multi-Operation Expression Parsing:** Evaluates compound mathematical expressions while enforcing standard operator precedence (`*`, `/` before `+`, `-`).
*   **Equation Solver:** Finds real and complex roots for second-order equations ($Ax^2 + Bx + C = 0$).

### 2. Number System Converter
*   Full support for bidirectional conversion between:
    *   Decimal
    *   Binary
    *   Octal
    *   Hexadecimal
*   Includes validation to ensure inputs match the selected number system (e.g., checking for non-binary digits).

### 3. Scientific & Engineering Module
*   **Power & Roots:** $x^y$ and square root calculations.
*   **Calculus & Discrete Math:** Factorials ($n!$) and Absolute values.
*   **Trigonometry:** Sine, Cosine, and Tangent (converts degrees to radians automatically).
*   **Logarithms:** Natural Log (Ln) and Base-10 Log.

## 🛠️ Technical Highlights
*   **Modular Architecture:** Each module (Arithmetic, Conversion, Scientific) is isolated into its own interface function.
*   **Robust Input Handling:** Uses `while(getchar() != '\n');` to clear the input buffer and prevent infinite loops on invalid entries.
*   **Math Library Integration:** Leverages `<math.h>` for precise scientific computations.
