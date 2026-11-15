
```markdown
# 🗺️ Adventure Game

A terminal-based C++ text adventure game featuring a quest system, inventory management, tavern minigames, and custom save file handlers. Developed as a console application utilizing modern C++ architecture.

## ✨ Features

* **Interactive Quest System:** Accept, track, and complete quests with dynamic objective updates.
* **Inventory Management:** Equip weapons, manage items, and handle consumable resources.
* **Tavern Minigames:** Engage in interactive tavern activities between adventures.
* **Persistent Saves:** Custom save/load file handlers to preserve your game progress.
* **Modular Codebase:** Clean separation of concerns with structured header (`include/`) and source (`src/`) directories.

## 🛠️ Tech Stack & Tools

* **Language:** C++
* **Build System:** CMake
* **Development Environment:** Visual Studio Code (MinGW-w64 / MSYS2 GCC toolchain)

## 📁 Project Structure

```text
Adventure-Game/
├── include/       # Header files (.hpp) for game entities, inventory, and quests
├── src/           # Implementation source files (.cpp)
├── CMakeLists.txt # CMake build configuration
└── README.md      # Project documentation

```

## 🚀 Getting Started

### Prerequisites

Make sure you have a modern C++ compiler supporting C++17 or higher and CMake installed on your system.

### Building and Running

1. Clone the repository:
```bash
git clone [https://github.com/Perry1231/Adventure-Game.git](https://github.com/Perry1231/Adventure-Game.git)
cd Adventure-Game

```


2. Configure the project with CMake:
```bash
mkdir build
cd build
cmake ..

```


3. Build the executable:
```bash
cmake --build .

```


4. Run the game binary generated in your build directory.

## 📜 License

Distributed under the MIT License. See `LICENSE` for more information.

```
