# LogHighlighter

**LogHighlighter** is a simple C++/ImGui application for visualizing and highlighting log files.  
Currently, it supports limited capabilities: it highlights log entries based on fixed keywords (e.g., `ERROR`, `WARN`, `INFO`).

---

## 🧪 How to Build

This project uses [CMake](https://cmake.org/) to build. You’ll need a C++17 compiler and CMake 3.14 or later.

1. Clone the repository:
   ```bash
   git clone https://github.com/yourusername/LogHighlighter.git
   cd LogHighlighter
   ```

2. Create a build directory:
   ```bash
   mkdir build && cd build
   ```

3. Build the app in **Release** mode:
   ```bash
   cmake ..
   cmake --build . --config Release
   ```

---

## ▶️ How to Use

Once built, you can run the app like this:

```bash
./LogHighlighter <log_file>
```

Example:

```bash
./LogHighlighter ~/logs/server.log
```

The selected log file will be visualized with color-coded lines for better readability.

---

## 📌 Features (Current)

- Highlighting for:
  - `ERROR`
  - `WARN`
  - `INFO`
  - `DEBUG`
- Scrollable viewer
- Simple GUI with line numbers

---

## 📜 License

This project is licensed under the [MIT License](LICENSE).
