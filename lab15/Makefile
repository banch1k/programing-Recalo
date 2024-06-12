CC = clang
LAB_OPTS = -I./src
C_OPTS = $(LAB_OPTS) -std=gnu11 -g -Wall -Wextra -Werror -Wformat-security -Wfloat-equal -Wshadow -Wconversion -Wlogical-not-parentheses -Wnull-dereference -Wno-unused-variable -Wno-implicit-int-float-conversion -Werror=vla

clean:
	rm -rf dist

prep:
	mkdir -p dist

compile: prep main.bin test.bin

main.bin: src/main.c src/list.c src/entity.c
	$(CC) $(C_OPTS) src/main.c src/list.c src/entity.c -o ./dist/main.bin

test.bin: test/test.c src/list.c src/entity.c
	$(CC) $(C_OPTS) test/test.c src/list.c src/entity.c -o ./dist/test.bin

test: clean prep compile
	LLVM_PROFILE_FILE="dist/test.profraw" ./dist/test.bin
	llvm-profdata merge -sparse dist/test.profraw -o dist/test.profdata
	llvm-cov report dist/test.bin -instr-profile=dist/test.profdata src/*.c
	llvm-cov show dist/test.bin -instr-profile=dist/test.profdata src/*.c --format html > dist/coverage.html

run: 
	./dist/main.bin

run_test:
	./dist/test.bin

check:
	clang-format --verbose -dry-run --Werror src/*
	clang-tidy src/*.c  -checks=-readability-uppercase-literal-suffix,-readability-magic-numbers,-clang-analyzer-deadcode.DeadStores,-clang-analyzer-security.insecureAPI.rand
	rm -rf src/*.dump

doxy:
	doxygen Doxyfile
