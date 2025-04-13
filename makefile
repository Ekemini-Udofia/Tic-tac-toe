project-root/
│
├── src/                   # Source code
│   ├── main.cpp           # Entry point
│   ├── core/              # Game logic
│   │   ├── game.cpp
│   │   ├── game.hpp
│   │   └── board.hpp      # If board logic is separate
│
│   ├── network/           # Networking code
│   │   ├── network.cpp
│   │   └── network.hpp
│
│   ├── gui/               # SDL GUI code
│   │   ├── renderer.cpp
│   │   ├── renderer.hpp
│   │   └── assets/        # Any image/sound files
│
├── include/               # Shared headers (optional)
│   └── config.hpp         # Shared constants/macros
│
├── build/                 # Compiled files (ignored in git)
│
├── CMakeLists.txt / Makefile  # Your build system
└── README.md
