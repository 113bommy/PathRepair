n=int(input())
a=[[] for i in range(n)]
i0=0
j0=0
k=0
b=[0 for i in range(n)]
for i in range(n):
    a[i]=[int(j) for j in input().split()]
    b[i]=0
    for j in range(n):
        b[i]+=a[i][j]
        if a[i][j]==0:
            i0,j0=i,j
            k=1
    if k==0: 
        B=b[i]
    k=0
if n==1:
    B=0
c=[0 for i in range(n)]
cb=0
bc=0
for j in range(n):
    c[j]=0
    cb+=a[j][j]
    bc+=a[j][n-1-j]
    for i in range(n):
        c[j]+=a[i][j]
p=0
for i in range(n):
    if i!=j0 and c[i]==B:
        p+=1
pp=0
for i in range(n):
    if i!=i0 and b[i]==B:
        pp+=1
        
if bc!=B and i0+j0!=n-1:
    print(-1)
   # print(cb,B,'cb')
elif cb!=B and i0!=j0:
    print(-1)
   # print(bc,B,'bc',i0,j0,i0+j0)
elif p!=n-1:
    print(-1)
   # print(p,B,'p')
elif pp!=n-1:
    print(-1)
elif n==1:
    print(1)
   # print(pp,B,'P')
elif i0!=j0 and j0+i0!=n-1:
    a1=B-b[i0]
    a2=B-c[j0]
    if a1==a2!=0 and B==bc==cb:
        print(a1)
    else:
        print(-1)
elif i0==j0 and i0+j0!=n-1:
    a1=B-b[i0]
    a2=B-c[j0]
    a3=B-cb
    if a1==a2==a3!=0 and B==bc:
        print(a1)
    else:
        print(-1)
elif i0!=j0 and i0+j0==n-1: 
    a1=B-b[i0]
    a2=B-c[j0]
    a3=B-bc
    if a1==a2==a3!=0 and B==cb:
        print(a1)
    else:
        print(-1)
elif i0==j0 and i0+j0==n-1: 
    a1=B-b[i0]
    a2=B-c[j0]
    a3=B-cb
    a4=B-bc
    if a1==a2==a3==a4!=0:
        print(a1)
    else:
        print(-1)