import sys
n = int(sys.stdin.readline())
ans = 0
t = 0
for i in range(n):
    a = int(sys.stdin.readline())
    if a==0:
        ans += t//2
        t = 0
    else:
        t += a
if t>0: ans += t//2
pritn(ans)