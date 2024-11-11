n = int(input())
lis = list(map(int,input().split()))
has=[0]*(1000002)
ans=0
for i in lis:
    has[i]+=1
for i in range(1000001):
    has[i+1]+=(has[i]//2)
    if(has[i]%2!=0):
        ans+=1
print(ans)            