import sys
import math
from collections import deque

def insertion_sort(a, n, g):
    ct = 0
    for i in range(g,n):
        v = a[i]
        j = i-g
        while j >= 0 and a[j] > v:
            a[j+g] = a[j]
            j = j-g
            ct += 1
        a[j+g] = v
    return ct

n = int(input())
a = list(map(int, sys.stdin.readlines()))
b = 701
ct= 0
g = deque([x for x in [701,301,132,57,23,10,1] if x < n])
while True:
    b = math.floor(2.25*b)
    if b > n:
        break
    g.appendleft(b)

for i in g:
    ct += insertion_sort(a, n, i)

print(len(g))
print(*g, sep=" ")
print(ct)
print(*a, sep="\n")