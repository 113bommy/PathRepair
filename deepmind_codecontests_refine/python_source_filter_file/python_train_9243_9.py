import sys
input = lambda : sys.stdin.readline().rstrip()
sys.setrecursionlimit(max(1000, 10**9))
write = lambda x: sys.stdout.write(x+"\n")


n = int(input())
s = input()
r = []
g = []
b = []
for i in range(3*n):
    if s[i]=="R":
        r.append(i)
    elif s[i]=="G":
        g.append(i)
    else:
        b.append(i)
from collections import defaultdict
d = defaultdict(list)
M = 10**9+7
for rr,gg,bb in zip(r,g,b):
    d[rr<gg, gg<bb, bb<rr].append(sorted([rr,gg,bb]))
ans = 1
def sub(l1, l2, l3):
    n = len(l1)
    l1.sort()
    l2.sort()
    l3.sort()
#     print(l1,l2,l3)
    ans = 1
    i2 = n-1
    i3 = n-1
    for i in range(n-1, -1, -1):
        while i2>=1 and l2[i2-1]>l1[i]:
            i2 -= 1
        ans *= (n - i2 - (n-(i+1)))
        ans %= M
    for i in range(n-1, -1, -1):
        while i3>=1 and l3[i3-1]>l2[i]:
            i3 -= 1
        ans *= (n - i3 - (n-(i+1)))
        ans %= M
    return ans%M

# for k in d.keys():
#     ans *= sub(*[[item[0] for item in d[k]], [item[1] for item in d[k]], [item[2] for item in d[k]]])
#     ans %= M
l1 = []
l2 = []
l3 = []
for k in d.keys():
    l1 += [item[0] for item in d[k]]
    l2 += [item[1] for item in d[k]]
    l3 += [item[2] for item in d[k]]
ans *= sub(l1,l2,l3)
ans %= M

for i in range(1, n+1):
    ans *= i
    ans %= M
print(ans%M)