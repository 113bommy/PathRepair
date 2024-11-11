n,m=map(int,input().split())
z=list(map(int,input().split()))
a=[]
for x in range(n):
    a.append(0)
for x in range(1,z[0]+1):
    a[z[x]]=1
    
z=list(map(int,input().split()))
b=[]
for x in range(m):
    b.append(0)
for x in range(1,z[0]+1):
    b[z[x]]=1
    
for i in range((n+1)*(m+1)):
    if a[i % n]==1 or b[i % m]==1:
        a[i % n]=1
        b[i % m]=1
f=True
for x in a:
    if x==0:
        f=False
        break
for x in b:
    if x==0:
        f=False        
        break
if f:
    print("YES")
else:
    print("NO")
