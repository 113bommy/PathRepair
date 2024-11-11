from bisect import *
n,r=map(int,input().split())
f=[]
f1=[]
for i in range(n):
    a=list(map(int,input().split()))
    if(a[1]>=0):
        f.append(a)
    else:
        f1.append([a[0]+a[1],a[0],a[1]])
flag=0
f.sort()
for i in f:
    if(i[0]<=r):
        r+=i[1]
        continue
    flag=1
    break
if(flag==1):
    print("NO")
    exit(0)
f1.sort(reverse=True)
for i in f1:
    if(i[1]<=r):
        r+=i[2]
        continue
    flag=1
    break
if(flag==1):
    print("NO")
    exit(0)
print("YES")
    
    
