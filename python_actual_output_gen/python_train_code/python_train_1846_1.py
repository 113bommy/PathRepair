n=int(input())
l=list(map(int,input().split()))
l.sort()
l1=[0]*n
j,ans=0,0
for i in range(1,n-1,2):
    l1[i]=l[j]
    j+=1
    
for i in range(0,n,2):
    l1[i]=l[j]
    j+=1

for i in range(1,n-1):
    if(l1[i]<l1[i+1] and l1[i]<l1[i-1]):
        ans+=1

print(ans)
print(*l1)
