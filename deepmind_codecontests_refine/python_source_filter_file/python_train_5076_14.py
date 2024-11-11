n,b=map(int,input().split())
a=list(map(int,input().split()))
if a[0]%2==0:
    o=0;e=1
else:
    o=1;e=0
c=[]
for i in range(1,n-1):
    if a[i]%2==0:e+=1
    else:o+=1
    if e==o:
        c.append(abs(a[i-1]-a[i]))
c.sort();sp=0;cu=0
for i in c:
    sp+=i
    if sp>b:
        break
    cu+=1
print(cu)