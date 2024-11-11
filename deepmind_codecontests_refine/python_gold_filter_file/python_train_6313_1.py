import sys
from bisect import bisect_left

def printf(format, *args):
    sys.stdout.write(format % args)

def puts(string):
    print(string)

n = int(input())
v = [int(x) for x in input().split()]
T = [int(x) for x in input().split()]
S = [0]*(n+1)
ans = [0]*(n+1)
extra = [0]*(n+1)
for i in range(n):
    if i-1 >= 0: S[i] = S[i-1]+T[i]
    else: S[i] = T[i]
S[n] = 10**20

for i in range(n):
    restar = 0
    if i > 0: restar = S[i-1]
    lo = bisect_left(S,v[i]+restar,lo=i)
    ans[i] += 1
    if lo==n: continue
    ans[lo] -= 1
    if lo > 0: extra[lo] += v[i]-S[lo-1]+restar
    else: extra[lo] += v[i]+restar

for i in range(n):
    if i-1 >= 0: ans[i] += ans[i-1]

for i in range(n):
    ans[i] = ans[i]*T[i] + extra[i]

print(" ".join(map(str,ans[0:n])))
