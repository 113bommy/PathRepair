from sys import *
input = stdin.readline

def nxt(l,s):
    for i,j in l:
        if j not in s:
            return i
    return 1<<9

from collections import defaultdict
n1,n2,n3,n4 = map(int,input().split())
a = sorted([j,i+1] for i,j in enumerate(map(int,input().split())))
b = sorted([j,i+1] for i,j in enumerate(map(int,input().split())))
c = sorted([j,i+1] for i,j in enumerate(map(int,input().split())))
d = sorted([j,i+1] for i,j in enumerate(map(int,input().split())))

m1,m2,m3 = defaultdict(set),defaultdict(set),defaultdict(set)
for i in range(int(input())):
    ai,bi = map(int,input().split())
    m1[bi].add(ai)
for i in range(n2):
    b[i][0]+=nxt(a,m1[b[i][1]])

for i in range(int(input())):
    ai,bi = map(int,input().split())
    m2[ai].add(bi)

for i in range(int(input())):
    ai,bi = map(int,input().split())
    m3[ai].add(bi)
for i in range(n3):
    c[i][0]+=nxt(d,m3[c[i][1]])

b.sort()
c.sort()

for i in range(n2):
    b[i][0]+=nxt(c,m2[b[i][1]])

print(min(b)[0] if min(b)[0]<1<<9 else -1)