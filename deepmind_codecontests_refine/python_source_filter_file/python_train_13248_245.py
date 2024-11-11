from sys import stdin
input = stdin.buffer.readline
for _ in range(int(input())):
    print(int(input()) >> 1 | 1)