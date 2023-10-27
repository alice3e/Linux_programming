g++ -O3 -fprofile-generate sha1_benchmark.cc sha1.cc -o sha1-with-opt
time ./sha1-with-opt
g++ -O3 -fprofile-use sha1_benchmark.cc sha1.cc -o sha1-with-opt
time ./sha1-with-opt

BEFORE
real	0m5.134s
user	0m5.117s
sys	0m0.016s

AFTER
real	0m4.396s
user	0m4.375s
sys	0m0.021s
