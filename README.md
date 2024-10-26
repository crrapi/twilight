# Twilight

Twilight is a C++ thread pool manager and task executor, designed for efficient task management in multi-threaded applications. The project leverages Bazel as a build system and Google Test for unit testing.

## Features

- **Thread Pool Manager**: Allows for dynamic task management with a configurable number of worker threads.
- **Task Executor**: Encapsulates tasks for flexible execution within the thread pool.
- **Logging Utility**: Provides basic logging for information, warnings, and errors.
- **Unit Tests**: Includes tests for the `ThreadPoolManager` and `TaskExecutor` classes using Google Test.

## Project Structure

```plaintext
Twilight/
├── WORKSPACE                # Bazel workspace file
├── BUILD                    # Main build configuration
├── src/
│   ├── BUILD                # Build rules for core library
│   ├── main.cpp             # Main entry point
│   ├── thread_pool_manager.h/cpp # Thread pool manager implementation
│   ├── task_executor.h/cpp       # Task executor implementation
│   └── utils/
│       ├── BUILD            # Build rules for utilities
│       ├── logging.h/cpp    # Simple logging utility
└── tests/
    ├── BUILD                # Build rules for tests
    ├── thread_pool_manager_test.cpp # Tests for ThreadPoolManager
    └── task_executor_test.cpp       # Tests for TaskExecutor
```

## Prerequisites

- **Bazel**: Install [Bazel](https://bazel.build/) to build and test the project.
- **Google Test**: Integrated as an external dependency; no need for separate installation.

## Getting Started

### 1. Clone the Repository

```bash
git clone https://github.com/your-username/Twilight.git
cd Twilight
```

### 2. Build the Project

To compile the main application:

```bash
bazel build //src:thread_pool_manager_app
```

### 3. Run the Application

Execute the application with:

```bash
bazel run //src:thread_pool_manager_app
```

### 4. Run the Tests

Run all tests to verify functionality:

```bash
bazel test //tests:all
```

## Usage

The main entry point initializes the `ThreadPoolManager` with a specific number of threads and enqueues tasks for execution. Here’s a basic usage example in `main.cpp`:

```cpp
#include "thread_pool_manager.h"

int main() {
    ThreadPoolManager manager(4); // Initialize with 4 threads
    manager.enqueueTask([]() { std::cout << "Task 1 running.\n"; });
    manager.enqueueTask([]() { std::cout << "Task 2 running.\n"; });
    
    manager.shutdown();
    return 0;
}
```

## Adding New Tasks

To add a new task, use `enqueueTask` on the `ThreadPoolManager` instance:

```cpp
manager.enqueueTask([]() { /* Task Code */ });
```

## Logging

A basic logging utility (`Logger`) is available and supports `INFO`, `WARNING`, and `ERROR` levels:

```cpp
Logger::log("Starting thread pool", INFO);
Logger::log("Task execution failed", ERROR);
```

## Contributing

Contributions are welcome! Please open an issue or submit a pull request for improvements or feature requests.

## License

This project is licensed under the MIT License.
