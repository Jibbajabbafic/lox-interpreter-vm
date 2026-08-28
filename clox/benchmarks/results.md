Results for the time and work benchmarks in each version

| Version | Time Benchmark (s) | Work Benchmark (batches) |
|---------|--------------------|--------------------------|
| Initial | 3.08986 | 5183 |
| Faster hash table probing | 2.58883s | 6456 batches |
| NAN Boxing | 2.53871s | 6584 batches |

# Environment:

## Operating System:
OS: Debian GNU/Linux 11 (bullseye)
Kernel: Linux 5.15.146.1-microsoft-standard-WSL2 x86_64
Platform: WSL2

## Compiler & Build Tools:
GCC: Debian 10.2.1-6
GNU Make: 4.3

## Hardware:
CPU: AMD Ryzen 9 5900X (24 logical cores, ~3.7 GHz)
RAM: 15 GiB
Swap: 4 GiB
