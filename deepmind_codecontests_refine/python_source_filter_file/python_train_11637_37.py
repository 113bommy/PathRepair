import sys
input = lambda : sys.stdin.readline().rstrip()
sys.setrecursionlimit(max(1000, 10**9))
write = lambda x: sys.stdout.write(x+"\n")


n = int(input())
a = list(map(int, input().split()))
b = list(map(int, input().split()))

# 二分探索木の代わり BST HST
# 存在しない要素に対するremoveはこないことを仮定している

h = []
from collections import Counter, defaultdict
from itertools import chain
ca = defaultdict(int)
ca.update(Counter(a))
cb = defaultdict(int)
cb.update(Counter(b))
ks = set(ca.keys()) | set(cb.keys())
ans = defaultdict(list)
done = 0
amari = 0
for k in ks:
    h.append((-ca[k], -cb[k], k))
h.sort(key=lambda x: x[0]+x[1])
la = []
lb = []
for va,vb,k in h:
    la.extend([k]*-va)
    lb.extend([k]*-vb)
na = [None]*n
nb = [None]*n
ia = 0
ib = n-1
ib2 = 0
for aa,bb,k in h:
    aa *= -1
    bb *= -1
    for _ in range(aa):
        na[ia] = k
        ia += 1
    for _ in range(bb):
        if na[ib]!=k:
            nb[ib] = k
            ib -= 1
        else:
            nb[ib2] = k
            ib2 += 1
if any((na[i]==nb[i]) for i in range(n)):
    print("No")
else:
    d = defaultdict(list)
    for i in range(n):
        d[la[i]].append(nlb[i])
    ans = []
    for i in range(n):
        ans.append(d[la[i]].pop())
    print("Yes")
    write(" ".join(map(str, ans)))