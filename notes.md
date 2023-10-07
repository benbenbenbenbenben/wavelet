build native:

```
clang++ -std=c++11 -O3 -Isrc -Iboost_1_83_0 -o example example.cpp src/core/wavelet.cpp src/core/filterbank.cpp src/core/attribute.cpp src/core/lowpass.cpp src/wavelets/paul.cpp src/wavelets/morlet.cpp
```
