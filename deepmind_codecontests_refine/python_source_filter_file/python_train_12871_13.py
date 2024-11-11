n,m=map(int,input().split())
x=0
for i in range(n-1,2*n):
    r=0
    for j in range(2,int(i**0.5+1)):
        if (i%j==0):
            r=1
            break
    if (r==0):
        x=i
        break
a=[[] for i in range(n+1)]
for i in range(1,n-1):
    a[i].append((i+1,1))
a[n-1].append((n,x-(n-2)))
j=1
l=3
for i in range(n,m+1):
   a[j].append((l,10**9))
   l+=1
   if (l==n+1):
       j+=1
       l=j+2
print(x,x)
for i in range(1,n+1):
    for j in range(len(a[i])):
        print(i,a[i][j][0],a[i][j][1])
