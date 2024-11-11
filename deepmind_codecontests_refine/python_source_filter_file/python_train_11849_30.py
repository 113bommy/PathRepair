from collections import Counter
n = int(input())
s = list(input())
C = Counter(s)
p = 1
for v in C.values():
    p = p * (v+1) % (10**9)

print(p-1)

