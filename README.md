# 📝 Text Analyzer

> A modular C++ engine for high-performance text statistics, powered by custom-built data structures.

## 📖 Context & Objectives

This project is a deep dive into **Software Architecture** and **Memory Management**. The goal is to move beyond isolated components and build a complete application that bridges low-level data structures with high-level logic.

### 🎯 Learning Goals

* **Modular Design:** Separating business logic from the user interface.
* **Data Structure Integration:** Real-world application of custom `Dynamic Array` and `Singly Linked List`.
* **API Design:** Understanding how a core engine communicates with various front-ends (Console/GUI).

---

## 🚀 Features

The application analyzes local text files to extract deep insights:

* ✅ **Text Tokenization:** Extracts words using alpha-character filtering (case-insensitive).
* ✅ **Word Statistics:** * Total word count.
* Unique word count.
* Word frequency mapping.


* ✅ **Ranking:** Configurable "Top N" most frequent words.
* ✅ **Clean Output:** Human-readable results displayed in the terminal.

---

## 🛠️ Technical Constraints

To ensure a deep understanding of computer science fundamentals, this project follows strict implementation rules:

* **Language:** C++17 (minimum).
* **The "No-STL" Rule:** Usage of `std::vector`, `std::list`, or `std::map` is **prohibited** in the core logic.
* **Custom Containers:** * `Dynamic Array` (Vector-like behavior).
* `Singly Linked List` (Forward-list behavior).


* **Code Quality:** Strict adherence to `const-correctness` and modularity.

---

## 🏗️ Architecture

The project follows a modular directory structure to allow for future front-end expansions (like a C# GUI).

```text
TextAnalyzer/
│
├── core/               # Business Logic (C++)
│   ├── analyzer.cpp/hpp    # Statistics & Analysis
│   └── tokenizer.cpp/hpp   # Word Extraction
│
├── containers/         # Custom Data Structures
│   ├── dynamic_array.hpp   # Custom Vector
│   └── sList.hpp           # Custom Linked List
│
├── app/                # Console Interface
│   └── main.cpp            # Entry Point
│
├── tests/              # Unit Testing (Optional)
└── README.md

```

---

## 📊 Modules Description

| Module | Responsibility |
| --- | --- |
| **`containers/`** | Pure data management. No business logic. |
| **`core/`** | File reading, tokenization, and statistical calculations. |
| **`app/`** | User interaction, calling the core API, and result formatting. |

---

## 🔮 Future Evolutions

* [ ] **C# Graphical Interface:** A WPF-based UI to visualize statistics.
* [ ] **Export Options:** Save results to `.json` or `.csv`.
* [ ] **Multi-file Support:** Batch processing of entire directories.
* [ ] **Memory Optimization:** Implementing a Hash Map for  lookups.

---

