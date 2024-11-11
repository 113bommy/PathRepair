n,k=list(map(int,input().split()))
a=[int(i) for i in input()]
i,j,l=0,-1,0
z=n
b=[]
c=-1
for i in range(n):
    if a[i]==0:
        c=i
    b.append(c)
c=-1
for i in range(n-1,-1,-1):
    if a[i]==0:
        c=i
    if c!=-1 and (b[i]==-1 or c<b[i]):
        b[i]=c
while i<n and j<n:
    if l<k+1:
        j+=1
        if j<n:
            l+=1-a[j]
        else:
            break
    else:
        z=min(z,max(j-b[(i+j)//2],b[(i+j)//2]-i),max(j-b[(i+j)//2+1],b[(i+j)//2+1]-i))
        l-=1-a[i]
        i+=1
print(z)