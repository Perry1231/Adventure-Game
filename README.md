Adventure-Game
A console-based text RPG written in C++ with procedural character generation, inventory management, and combat systems. Designed as a learning project to demonstrate object-oriented programming, class hierarchies, and game architecture.

About the Project
Adventure-Game is a turn-based text adventure where you create a random hero, manage equipment, and explore a dynamic world. The game generates unique characters with different races, professions, and stats — no two playthroughs are the same.

What's inside?
Random Character Generation — 5 races, multiple professions per race, randomized names and stats
Stats System — Health, Strength, Agility, Intelligence, Defense, and Gold, with values adjusted by profession
Equipment — Weapons and Armor with durability, enchantment, and breaking mechanics
Inventory Management — Add, remove, and view items; dynamic inventory resizing
Trade System — Interact with traders (in development)
Event System — Random encounters (in development)
Pure C++ — No external libraries required for the compiled version; runs standalone on Windows
Getting Started
Option 1: Download and Run (Recommended)
No compiler or development tools needed.

Go to the Releases section of this repository
Download AdventureGame.zip
Extract the archive
Run AdventureGame.exe
The game will start in a console window.

Note: If Windows Defender warns you about the file, click More info → Run anyway. This is a locally compiled application.

Option 2: Build from Source
For developers who want to view or modify the code.

Requirements
C++ compiler: GCC / MinGW, MSVC, or Clang
Git (to clone the repository)
Code editor: Visual Studio Code (recommended), Visual Studio, or CLion
Clone the repository
git clone https://github.com/Perry1231/Adventure-Game.git
cd Adventure-Game
Build with g++ (Windows / Linux / macOS)
g++ -static-libgcc -static-libg++ -static *.cpp -o AdventureGame.exe
The -static flags ensure the executable runs on any Windows PC without requiring MSYS2/MinGW DLLs.

Build with Visual Studio Code
Install the C/C++ Extension by Microsoft
Open the project folder
Press Ctrl+Shift+B and select "C/C++: g++.exe build all"
The build output (AdventureGame.exe) will appear in the project folder
Build with Visual Studio
Open Visual Studio → Open a Local Folder
Select the Adventure-Game folder
Build → Build Solution
Run with Local Windows Debugger
Gameplay Overview
Character Creation
Every time you launch the game, a new hero is generated with:

Race	Available Professions
Human	Warrior, Mage, Rogue, Peasant
Elf	Archer, Druid, Ranger
Dwarf	Blacksmith, Miner, Berserker
Orc	Shaman, Warlord, Berserker
Goblin	Thief, Assassin, Scavenger
Each profession has unique base stats and growth. Names are randomly selected from lore-friendly lists.

Stats
Health — Vitality; varies by profession
Strength — Physical damage output
Agility — Speed and critical hit chance
Intelligence — Magic power and skill efficiency
Defense — Damage reduction
Gold — Currency for trading
Equipment & Inventory
Weapons — Equippable items with attack power, durability, and value
Armor — Defensive equipment with protection and durability
Inventory — Dynamic container supporting add, remove, and inspection commands
Items can break when durability reaches zero. Enchanted items provide bonus effects (work in progress).

Trade (Planned)
Buy and sell items with NPC traders to upgrade your gear.

Events (Planned)
Random encounters while exploring the world.

Project Structure
Adventure-Game/
├── Adventu reGame.exe      ← Compiled executable (static build)
├── Header.h                ← Class definitions: Item, Character, Weapon, Armory, Inventory
├── Main.cpp                ← Entry point, character & inventory initialization
├── Character.cpp           ← Character creation, stats, name & race generation
├── Weapon.cpp              ← Weapon logic: durability, breaking, randomization
├── Armory.cpp              ← Armor system (stub, implementation pending)
├── Inventory.cpp           ← Inventory container, add/remove/display logic
├── Plot.cpp                ← Story/plot system (placeholder)
├── Trade.cpp               ← Trading system (placeholder)
├── Evets.cpp               ← Event system (placeholder)
├── Other.cpp               ← Additional adjustments (placeholder)
├── OtherCharacter.cpp      ← NPC characters (placeholder)
├── Addition.cpp            ← Helper functions
└── .vscode/
    └── tasks.json          ← Build configuration for VS Code
Troubleshooting
"g++ is not recognized"
GCC is not installed or not in PATH. Install one of:

MinGW — mingw-w64
MSYS2 — msys2.org
Visual Studio C++ Build Tools
Then restart your terminal and verify with:

g++ --version
Windows Defender blocks the .exe
Unsigned executables may trigger SmartScreen. This is normal for a hobby project. Click More info → Run anyway.

Game crashes on startup
Make sure you downloaded the Release version, not the source ZIP. If the problem persists, open an issue with your Windows version and error message.

Automatic Builds
This repository uses GitHub Actions to compile the game automatically on every release. You can download pre-built executables from:

Repository → Actions → Latest Build → Artifacts
No manual compilation required for end users.

Contributing
This is a student/learning project. Feel free to open issues for bugs or suggestions. Pull requests are welcome.

Fork the repository
Create a feature branch: git checkout -b feature/awesome-feature
Commit your changes: git commit -m "Add awesome feature"
Push to the branch: git push origin feature/awesome-feature
Open a Pull Request
Author
Made by Vladyslav Vytrykush as a C++ programming portfolio project.

License
This project is open source. See LICENSE for details (if applicable).

Roadmap
 Basic character generation (races + professions)
 Weapon and Armor classes with durability
 Inventory system
 Full combat system
 Plot and quests
 Save/Load system
 Multiple enemy types
 Linux/macOS support testing
