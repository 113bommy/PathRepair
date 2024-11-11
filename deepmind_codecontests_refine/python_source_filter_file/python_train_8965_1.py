from itertools import *
n = int(input())
for _ in range(n):
    l1, r1, l2, r2 = list(map(int, input().split()))
    print("{} {}", l1, l2 if l1 != l2 else r2)
