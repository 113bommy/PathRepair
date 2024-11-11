n,k=map(int,input().split())
if n==k:
    print(-1)
else:
    a=[]
    a.append(n-k)
    for i in range(1,n-k):
        a.append(i)
    for j in range(n-k+1,n):
        a.append(j)
    print(*a)