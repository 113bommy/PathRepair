import math
t = int(input())

def get(A,B,N):
    if(N==-1):
        return 0;
    if(max(A,B) > N):
        return N + 1
    GCD = int(math.gcd(A,B))
    X = GCD * (A//GCD) * (B//GCD)
    Delta = min(max(A,B), N - N//X*X + 1)
    return max(A,B) + max(N//X-1,0)*max(A,B) + (Delta * int(N>X))

for _ in range(t):
    a,b,q = map(int,input().split())
    for _ in range(q):
        l,r = map(int,input().split())
        ans = abs(l-r) + 1 - (get(a,b,r) - get(a,b,l-1))
        print(int(ans),end=' ')
    print()
