def gn(n,k):
    k -= 1
    r = k+2*n+n//2 - (1 + 2*k + 2*n)
    if r < 0:
        print(-1)
        return
    print(k+1, 2*n+k, 3*n+k)
    n-=1
    k+=1
    for i in range(1, n+1):
        x = i
        y = n+(i-((n+1)//2)+n)%n+1
        print(k+x, k+y, 2*k+x+y+r)
def kn(n,k):
    k -= 1
    r = k+2*n+(n+1)//2 - (1 + 2*k + 2*n)
    if r < 0:
        print(-1)
        return
    for i in range(1, n+1):
        x = i
        y = n+(i-((n+1)//2)+n)%n+1
        print(k+x, k+y, 2*k+x+y+r)

N, K = map(int, input().split())
if N%2:
    kn(N,K)
else:
    gn(N,K)
