import sys
input = lambda : sys.stdin.readline().rstrip()
sys.setrecursionlimit(max(1000, 10**9))
write = lambda x: sys.stdout.write(x+"\n")


k,q = map(int, input().split())
d = list(map(int, input().split()))

def sub(n,x,m):
    X = 0
    init = x%m
    x%=m
    if n<=k:
        for i in range(n-1):
            if x<(x+d[i])%m:
                X += 1
            x = (x+d[i])%m
        ans = X
    else:
        for i in range(k):
            if x<(x+d[i])%m:
                X += 1
            x = (x+d[i])%m
        diff = (x-init)
        ans = ((n-1)//k) * X - (init + (diff*((n-1)//k))) // m
        nn = n-((n-1)//k)*k
        xx = (init + (diff*(n//k))) % m
#         if xx<init:
#             ans -= 1
        for i in range(nn-1):
            if xx<(xx+d[i])%m:
                ans += 1
            xx = (xx+d[i])%m
    return ans
#         else:
#             ans = (n//k) * X + (init + (diff*(n//k)))
ans = [None]*q
for i in range(q):
    n,x,m = map(int, input().split())
    ans[i] = sub(n,x,m)
write("\n".join(map(str, ans)))