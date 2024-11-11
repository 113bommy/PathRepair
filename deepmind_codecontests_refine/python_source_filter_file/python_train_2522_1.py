n,m,k=map(int,input().split())
a=list(map(int,input().split()))
b=list(map(int,input().split()))
d1=[0]*(len(a)+1)
flag=False
ct=0
i=0
while i<n:
    if a[i]==0:
        i+=1
        continue
    j=i
    while j<n and a[j]==1:
        j+=1
    for l in range(1,j-i+1):
        d1[l]+=j-i-l+1
    i=j


    
d2=[0]*(len(b)+1)
i=0
while i<m:
    if b[i]==0:
        i+=1
        continue
    j=i
    while j<m and b[j]==1:
        j+=1
    for l in range(1,j-i+1):
        d2[l]+=j-i-l+1
    i=j


    
ans=0
#print(d1,d2)
for i in range(1,len(d1)):
    if k%i==0 and k//i<m:
        ans+=d1[i]*d2[k//i]
        
print(ans)
#1 0 0 1 0 1 1 1 1 1 1 1 1 1 1 1 1 1 1 0 1 1 1 0 1 0 1 1 1 1 1 1 1 1 1 1 1 1 1 0 1 1 1 1 0 1 1 1 0 1
#1 1 0 1 0 1 1 0 1 1 1 1 1 1 0 1 1 0 1 0 0 1 1 1 1 0 0 1 0 1 1 1 0 1 1 1 1 1 1 1 1 1 1 0 1 1 1 1 1 0
