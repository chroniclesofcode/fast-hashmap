# fast-hashmap
C++ fast, efficient, cache-friendly hash table implementation with tests and benchmarking.

TO-DO:
- Implement SSE instructions in matching
- Implement find
- Implement insert
- Implement erase
- Implement detailed iterators
- Stop sentinel at the end (make sure it can not be accessed! (extra element?))
- Create the control variables in the same allocation block
- Write tests via gmock
- Adjust for false sharing
- Benchmark via Google benchmark
- Compare with same tests against multiple hashmaps
  - Try different hash sizes
  - Try different data types

DONE:
- Implement groups
- Implement basic iterators for casual use