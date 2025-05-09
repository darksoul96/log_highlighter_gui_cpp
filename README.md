# LogHighlighter

**LogHighlighter** is a simple C++/ImGui application for visualizing and highlighting log files.  
Currently, it supports limited capabilities: it highlights log entries based on fixed keywords (e.g., `ERROR`, `WARN`, `INFO`).

---

## 🔧 Developer Requirements

To build this project from source, the following tools and libraries are required:

### ✅ Tools

| Tool              | Purpose                        | Install Command (Debian/Ubuntu)           |
|-------------------|--------------------------------|-------------------------------------------|
| **CMake ≥ 3.14**  | Build system generator         | `sudo apt install cmake`                  |
| **g++ / clang++** | C++17 compiler                 | `sudo apt install build-essential`        |

### ✅ Libraries

| Library           | Purpose                        | Install Command                           |
|-------------------|--------------------------------|-------------------------------------------|
| **OpenGL**        | Rendering backend              | `sudo apt install libgl1-mesa-dev`        |
| **X11**           | GUI windowing (used by GLFW)   | `sudo apt install libx11-dev xorg-dev`    |

> These are usually available on most Linux distributions and don't need to be installed on macOS if you're using Xcode.

Once installed, follow the [build instructions](#-how-to-build) to compile the app.


## 🧪 How to Build

This project uses [CMake](https://cmake.org/) to build. You’ll need a C++17 compiler and CMake 3.14 or later.

1. Clone the repository:
   ```bash
   git clone https://github.com/darksoul96/log_highlighter_gui_cpp.git
   cd LogHighlighter
   ```

2. Create a build directory:
   ```bash
   mkdir build && cd build
   ```

3. Build the app in **Release** mode:

#### 🔸 macOS / Linux (terminal)

```bash
   mkdir build && cd build
   cmake .. -DCMAKE_BUILD_TYPE=Release
   cmake --build .
```

#### Windows' Visual Studio
```bash
   cmake .. -G "Visual Studio 17 2022"
   cmake --build . --config Release
```

#### Xcode MacOS
```bash
   cmake .. -G "Xcode"
   cmake --build . --config Release
```

---

## ▶️ How to Use

Once built, you can run the app like this from the /build directory:

```bash
./LogHighlighter <log_file_path> <rules_file_path> <flags>
```
There's a rules pattern file already included by the name "rules.config".

Example:

```bash
./LogHighlighter ~/logs/server.log ~/rules/rules.config --light-bg
```

The selected log file will be visualized with color-coded lines for better readability. These colors and pattern matching can be configured to your needs from the rules.config file which you need to pass as the third argument.

---

## 📌 Features (Current)

- Highlighting for:
  - `ERROR`
  - `WARN`
  - `INFO`
  - `DEBUG`
  - Etc
All configurable from your own rules file for better pattern matching an colors.
- Scrollable viewer
- Simple GUI with line numbers
- Fast even for larger files compared to other viewers

- Search field

- Text wrapping

- List of available flags include:
--light-bg > Light background color

---

## 📜 License

This project is licensed under the [MIT License](LICENSE).
