n,k=map(int,input().split())
a=list(map(int,input().split()))

cnt=1
res=1

for i in range(n-1):
    if a[i]!=a[i+1]:
        cnt+=1
    else:
        res= max(res,cnt)
        cnt=1
print(res)
