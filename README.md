# lox

lox compiler in C++.

## Build

```
bazel run //:cox-entry
```

## Run

Compiling a lox file:

```
./bazel-bin/lox [filePath]
```

Running the REPL:

```
./lox
```

## VSCode Setup

Install the clangd extension, then run `bazel run @hedron_compile_commands//:refresh_all` to generate the `compile_commands.json`.
