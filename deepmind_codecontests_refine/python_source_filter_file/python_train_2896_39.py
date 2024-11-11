import sys
from itertools import accumulate, combinations

read = sys.stdin.read

N, K, *a = map(int, read().split())

a = accumulate([0] + a)
seq = []
for i, j in combinations(a, 2):
    seq.append(j - i)

m = (10 ** 9 * 1000).bit_length()
answer = 0
bit = 1 << m
for _ in range(m):
    tmp = bit + answer
    if len([i for i in seq if i & tmp == tmp]) >= K:
        answer = tmp
    bit >>= 1

print(answer)