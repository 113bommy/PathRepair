n,k,m=map(int,input().split())
A=sorted(list(map(int,input().split())))
list.reverse(A)
Sum=.0; Ans=.0
for i in range(n):
    Sum+=A[i]
    t=n-i-1 #deled
    if m>=n-i-1:
        Ans=max(Ans,(Sum+min(m-t,(i+1)*k))/(i+1))
print(Ans)
