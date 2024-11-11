n=int(input())
a=list(map(int,input().split()))

l=[0]*(10**6)
ans=0
#print(l)
for i in a:
    if l[i]==0:
        for j in range(i,10**6,i):
            l[j]+=1
    else:
        l[i]+=1
for i in a:
    if l[i]==1:
        ans+=1
print(ans)