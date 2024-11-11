N=int(input())
A=[int(input()) for range(N)]
X=min(A)
ans=(N+X-1)//X +4
print(ans)