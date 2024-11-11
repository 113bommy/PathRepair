n,m=map(int,input().split())
l=[0]*1000
f=1
for i in range(n):
    a,b=map(int,input().split())
    if a==0:
        l[0]=1
    a+=1
    for j in range(a,b+1):
        l[j]=1
for i in range(m):
    if l[i]==0:
        f=0
        break
print(l)
if f==0:
    print("NO")
else:
    print("YES")
    
        
    
    
