import os
import sys
from collections import Counter

def log(*args, **kwargs):
    if os.environ.get('CODEFR'):
        print(*args, **kwargs)


n = int(input())
#a = list(map(int,input().split()))
c = Counter()
for i in range(n):
    s = input()
    c[s[0]] += 1

r = 0
for i in c.values():
    b = i // 2
    c = i - b
    d = b * (b - 1) / 2 + c * (c - 1) /2
    r += d
print(r)
