from math import ceil, log2
from collections import deque
from sys import stdin
input = stdin.readline
def read(): return [int(i) for i in input().split()]

n = int(input())
l = list(read())
m = min(l)
if n<m:
    print(-1)
    exit()
q = 0
for i in range(9):
    if m==l[i]:
        q=i+1

s = n//l[q-1]

ans = [q]*s
r = n%l[q-1]
l = [i-m for i in l]
#print(ans,r)
for i in range(s):
    for j,v in enumerate(reversed(l)):
        if v<=r:
            ans[i] = 9-j
            r-=v
            break

print(''.join(map(str, ans)))


