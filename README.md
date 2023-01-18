# fibonacci

A library of Fibonacci number generators.

## Building

```bash
cmake -E make_directory "build"
cmake -DCMAKE_BUILD_TYPE=Release -S . -B "build"
cmake --build "build" --config Release
```

## Testing

```bash
cmake -E chdir "build" ctest --build-config Release
```

## Benchmarking

```bash
cmake -E chdir "build" ./bin/fibonacci_benchmarks
```
