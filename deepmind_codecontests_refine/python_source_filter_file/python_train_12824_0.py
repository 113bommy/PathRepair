n,m=map(int,input().split())
maxi=1000009
d={}
a=[['0'] for i in range(n+1)]

for i in range(m):
    u,v=map(int,input().split())
    a[u].append(str(v))
    a[v].append(str(u))

count=1
for i in range(1,n+1):
    if len(a[i])==1:
        print("-1")
        exit(0)
    a[i].sort()
for i in range(1,n+1):    
    a[i]="".join(a[i])
    #print(a[i])
for i in range(1,n+1):
    if a[i] not in d:
        d[a[i]]=count
        count+=1
#print(d)  
if len(d)!=3:
    #print(s)
    print("-1")
    exit(0)
for i in range(1,n+1):
    print(d[a[i]],end=" ")
  