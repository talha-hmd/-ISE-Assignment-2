# C++ Game Suite — Palindrome Checker, Hangman, Tic-Tac-Toe

A collection of three small, beginner-friendly **C++ console games** for ISE Assignment, each built to demonstrate clean programming practices, modular design, and robustness. These projects were written for an **Introduction to Software Engineering (ISE)** course, focusing on:

* **Anticipation of Change** — easily adaptable code
* **Meaningful Variable Names** — clear and descriptive
* **Modularity** — each task handled by a separate function
* **Documentation** — consistent comments explaining logic
* **Robustness** — input validation and graceful error handling

---

## Contents

### 1. Palindrome Checker

Determines if an input string or phrase is a palindrome (reads the same forwards and backwards).

**Features:**

* Ignores case, spaces, and punctuation
* Supports multiple inputs per session
* ESC key to exit gracefully

**Example:**

```
Enter a word or phrase: Madam, I'm Adam
Palindrome
```

---

### 2. Hangman Game

A text-based guessing game where the player guesses letters to reveal a hidden word.

**Features:**

* Reads words from an external `words.txt` file
* Limits mistakes to 7 attempts
* Rejects invalid or repeated guesses
* Gracefully handles missing files or empty lists

**Example:**

```
=== Hangman Game ===
You have 7 mistakes allowed.
Current Word: _ _ _ _ _
Enter a letter: a
Correct guess!
```

---

### 3. Tic-Tac-Toe

A two-player turn-based game (Player X vs Player O) on a 3x3 board.

**Features:**

* Full input validation (no crashes on bad input)
* Detects wins, draws, and occupied cells
* Replay option after each match

**Example:**

```
Current Board:
 X | O | X
---+---+---
 O | X | O
---+---+---
 X |   | O
Player X wins!
```

---

## 🧠 Design Philosophy

Each program emphasizes **clarity and maintainability** over complexity. Code is written to be beginner-readable with:

* Detailed comments above every function
* Clean separation of logic and I/O
* Constant definitions for easy tuning (e.g., grid size, max mistakes)

---

## Author

**Talha**
Undergraduate Student – Introduction to Software Engineering
📍 Pakistan

---
