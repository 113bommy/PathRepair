n=int(input())
l=[int(i) for i in input().split()]
ans=0
for i in range(3,n-2):
    if l[i]==l[i-2]==l[i+2]==1 and l[i-1]==l[i+1]==0:
        ans+=1
        l[i]=0
for i in range(1,n-1):
    if l[i-1]==l[i+1]==1 and l[i]==0:
        ans+=1
        l[i+1]=1
print(ans)        
