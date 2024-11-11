n = int(input())
lis=[0]+sorted(map(int,input().split()))
ans=0
aa=[]
cou=0
for i in range(1,n+1):
    if lis[i]>=cou:
        ans+=1
        cou+=lis[i]
print(ans)         
