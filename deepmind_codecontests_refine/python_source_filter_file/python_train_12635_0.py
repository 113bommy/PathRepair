n,k=map(int,input().split())
l=list(map(int,input().split()))
c=0
for i in l:
    if i<0:
        c+=1
#print(c)
ans=0
if k<=c:
    for i in range(k):
        l[i]*=-1 
else:
    k-=c 
    for i in range(c):
        l[i]*=-1
    
    if k%2:
        ans=(-2)*min(l)
        
    #print(l,k)
print(sum(l)-ans)
    