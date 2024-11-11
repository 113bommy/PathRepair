import math
rr = lambda: input().strip()
rrm = lambda: map(int, rr().split())

def solve():
    a,b,x,y,n = rrm()
    n1 = n
    if(a+b-x-y<=n):
        return x*y

    ans = 0
    t1 = max(b-n,y)
    n -= (b-y)
    t2 = max(a-n,x)
    ans = t1*t2

    n = n1
    t1 = max(a-n,x)
    n -= (a-x)
    t2 = max(b-n,y)
    ans = min(ans, t1*t2)
    return ans

T = int(rr())
for _ in range(T):
    ans = solve()

    print(ans)