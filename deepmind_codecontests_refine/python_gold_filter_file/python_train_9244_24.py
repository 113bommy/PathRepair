N=int(input())
A=[int(input()) for i in range(5)]
X=min(A)
ans=(N+X-1)//X +4
print(ans)