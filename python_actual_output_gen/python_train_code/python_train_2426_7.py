n,m=map(int,input().split())
k=0
for i in range(max(n,m)):
    b=i
    a=(n-b)**0.5
    if m-b**2==a:
        k+=1
print(k)
