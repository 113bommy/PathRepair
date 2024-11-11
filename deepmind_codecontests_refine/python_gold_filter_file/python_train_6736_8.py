n,k,l = map(int,input().split())
lst = list(map(int,input().split()))
lst.sort()
x,res,cout=lst[0]+l,0,0
for i in range(0,n*k,k):
    if lst[i]>x:break
    res+=lst[i]
    cout+=1
for j in range(i,-1,-1):
    if cout==n:break
    if lst[j]<=x and j%k!=0:
        cout+=1;res+=lst[j]
if cout==n:print(res)
else:print(0)