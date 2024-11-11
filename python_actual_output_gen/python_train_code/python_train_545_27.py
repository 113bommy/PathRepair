n=int(input())
a=list(map(int,input().split()))
ans=[0]*(n+1)
for i in range(n,0,-1):
    temp=0
    for j in range(i,n+1,i): temp+=ans[j]
    if a[i-1]!=temp%2: ans[i]=1
print(sum(ans))           
for i in range(n):
    if ans[i]==1: print(i,end=" ")