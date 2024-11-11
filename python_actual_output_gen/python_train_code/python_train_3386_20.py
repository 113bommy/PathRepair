L1=input().split()
n=int(L1[0])
x=int(L1[1])
L=[]
for i in range(n):
    a=input().split()
    L.append(a)
for i in range(n):
    L[i][0]=int(L[i][0])
    L[i][1]=int(L[i][1])
ans=L[0][0]%x+L[0][1]-L[0][0]+1
for i in range(1,n):
    b=L[i][0]-L[i-1][1]-1
    if b<x:
        ans+=x
    else:
        ans+=b%x
    ans+=L[i][1]-L[i][0]+1
print(ans)
