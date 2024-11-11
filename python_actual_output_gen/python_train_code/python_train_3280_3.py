n=int(input())
arr=list(map(int,input().split()))
d={}
mn=1000000000
ans=0
for i in range(0,n):
    if(mn>arr[i]):
        mn=arr[i]
        ans=i+1
    b=arr[i]    
    if(d.get(b,0)):
        d[b]+=1
    else:
        d[b]=0    
if(d[mn]>1):
    print("Still Rozdil")
else:
    print(ans)


