n,k=map(int,input().split())
if n==k:
    print(-1)
else:
    a=[]
    a.append(n-k)
    for i in range(1,k):
        a.append(i)
    for j in range(k,n):
        a.append(j)
    print(*a)