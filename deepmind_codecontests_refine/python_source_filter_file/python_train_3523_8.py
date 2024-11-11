#!/usr/bin/env python3

H, W = list(map(int, input().split()))
N = int(input().split()[0])
a_list = list(map(int, input().split()))

c_list = []

for i, a in enumerate(a_list):
    c_list += [i + 1] * a

for i in range(H):
    w_list = c_list[H * i : H * i + W]
    if i % 2 == 1:
        w_list = reversed(w_list)
    print(" ".join([str(w) for w in w_list]))
