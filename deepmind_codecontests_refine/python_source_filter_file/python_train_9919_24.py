import sys
from math import ceil
inp = sys.stdin.read().strip().split('\n')[1:]
out = []
for i in inp:
    n, x = map(int, i.split())
    out.append(int(ceil((n - 2) / x + 1)))
print(*out, sep='\n')
