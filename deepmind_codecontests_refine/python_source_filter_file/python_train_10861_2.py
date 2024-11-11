import sys
import io, os
input = sys.stdin.readline

k = int(input())
s = list(str(input().rstrip()))

s.reverse()

n = 1<<k
C = [1]*(2*n)

def update(i):
    if s[i] == '0':
        C[i] = C[2*i+2]
    elif s[i] == '1':
        C[i] = C[2*i+1]
    else:
        C[i] = C[2*i+1]+C[2*i+2]

for i in range(n-2, -1, 1):
    update(i)

q = int(input())
for i in range(q):
    p, c = map(str, input().split())
    p = int(p)
    p = n-1-p
    s[p] = c
    while p:
        update(p)
        p = (p-1)//2
    update(0)
    print(C[0])
