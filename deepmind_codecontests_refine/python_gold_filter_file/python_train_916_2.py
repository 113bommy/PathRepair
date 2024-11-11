N=int(input())
A=list(map(int,input().split()))
d={}
sum=0
d[sum]=1
for i in range(N):
    sum+=A[i]
    if sum in d:
        d[sum]+=1
    else:
        d[sum]=1
ans=0
for x in d:
        ans+=d[x]*(d[x]-1)//2 # 1*0//2=0
print(ans)