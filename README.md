# kvstore

A crash-safe key-value store written from scratch in C++17 (a tiny Redis).

## Status
- [x] Stage 0 – tools installed
- [x] Stage 1 – in-memory store (`SET` / `GET` / `DEL`)
- [ ] Stage 2 – project structure + tests
- [ ] Stage 3 – write-ahead log (crash safety)
- [ ] Stage 4 – TCP server
- [ ] Stage 5 – threads
- [ ] Stage 6 – compaction
- [ ] Stage 7 – benchmark

## Build and run (in Ubuntu / WSL)
```bash
cd /mnt/d/kvstore
cmake -S . -B build      # set up the build (only needed once)
cmake --build build      # compile
./build/kvstore          # run
ctest --test-dir build --output-on-failure   # run the automated tests
```

## Example
```
> SET name Vaishnavi
OK
> GET name
Vaishnavi
> DEL name
deleted
> GET name
(not found)
```
