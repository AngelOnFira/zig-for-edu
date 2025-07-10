# Justfile for Zig CC Assessment

# Default recipe - show available commands
default:
    @just --list

# Compile all examples with both gcc and zig cc
compile-all: compile-gcc-all compile-zig-all

# Run all examples with both compilers
run-all: run-gcc-all run-zig-all

# === GCC Commands ===

# Compile all examples with gcc
compile-gcc-all: compile-gcc-1 compile-gcc-2 compile-gcc-3 compile-gcc-4 compile-gcc-5 compile-gcc-6

# Compile individual examples with gcc
compile-gcc-1:
    gcc -Wall -Wextra -o example1_gcc example1.c 2>&1 || true

compile-gcc-2:
    gcc -Wall -Wextra -o example2_gcc example2.c 2>&1 || true

compile-gcc-3:
    gcc -Wall -Wextra -o example3_gcc example3.c 2>&1 || true

compile-gcc-4:
    gcc -Wall -Wextra -o example4_gcc example4.c 2>&1 || true

compile-gcc-5:
    gcc -Wall -Wextra -o example5_gcc example5.c 2>&1 || true

compile-gcc-6:
    gcc -Wall -Wextra -o example6_gcc example6.c 2>&1 || true

# Run all gcc-compiled examples
run-gcc-all: run-gcc-1 run-gcc-2 run-gcc-3 run-gcc-4 run-gcc-5 run-gcc-6

# Run individual gcc examples
run-gcc-1:
    ./example1_gcc 2>&1 || true

run-gcc-2:
    ./example2_gcc 2>&1 || true

run-gcc-3:
    ./example3_gcc 2>&1 || true

run-gcc-4:
    ./example4_gcc 2>&1 || true

run-gcc-5:
    ./example5_gcc 2>&1 || true

run-gcc-6:
    ./example6_gcc 2>&1 || true

# === Zig CC Commands ===

# Compile all examples with zig cc
compile-zig-all: compile-zig-1 compile-zig-2 compile-zig-3 compile-zig-4 compile-zig-5 compile-zig-6

# Compile individual examples with zig cc
compile-zig-1:
    zig cc -Wall -Wextra -o example1_zig example1.c 2>&1 || true

compile-zig-2:
    zig cc -Wall -Wextra -o example2_zig example2.c 2>&1 || true

compile-zig-3:
    zig cc -Wall -Wextra -o example3_zig example3.c 2>&1 || true

compile-zig-4:
    zig cc -Wall -Wextra -o example4_zig example4.c 2>&1 || true

compile-zig-5:
    zig cc -Wall -Wextra -o example5_zig example5.c 2>&1 || true

compile-zig-6:
    zig cc -Wall -Wextra -o example6_zig example6.c 2>&1 || true

# Run all zig-compiled examples
run-zig-all: run-zig-1 run-zig-2 run-zig-3 run-zig-4 run-zig-5 run-zig-6

# Run individual zig examples
run-zig-1:
    ./example1_zig 2>&1 || true

run-zig-2:
    ./example2_zig 2>&1 || true

run-zig-3:
    ./example3_zig 2>&1 || true

run-zig-4:
    ./example4_zig 2>&1 || true

run-zig-5:
    ./example5_zig 2>&1 || true

run-zig-6:
    ./example6_zig 2>&1 || true

# === Utility Commands ===

# Clean all compiled binaries
clean:
    rm -f example*_gcc example*_zig

# Show sizes of compiled binaries
sizes:
    @echo "Binary sizes:"
    @ls -lh example*_gcc example*_zig 2>/dev/null || echo "No binaries found. Run 'just compile-all' first."

# Compile and run a specific example with both compilers
test-example NUM:
    @echo "=== Testing Example {{NUM}} ==="
    @echo "\n--- GCC Compilation ---"
    @just compile-gcc-{{NUM}}
    @echo "\n--- GCC Runtime ---"
    @just run-gcc-{{NUM}}
    @echo "\n--- Zig CC Compilation ---"
    @just compile-zig-{{NUM}}
    @echo "\n--- Zig CC Runtime ---"
    @just run-zig-{{NUM}}