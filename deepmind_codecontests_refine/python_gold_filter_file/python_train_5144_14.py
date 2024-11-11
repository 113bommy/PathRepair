n,m=map(int, input().split())
l=list(map(int, input().split()))
u=[]
for i in l:
    if(i<0):
        u.append(i)
u.sort()        
#print(l)
ans=0
for i in range(min(m,len(u))):
    ans+=abs(u[i])
print(ans)    
    