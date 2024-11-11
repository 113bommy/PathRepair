n,m=map(int,input().split())
a=[]
b=[]
ans =0 
for i in range(n):   
    a.append(0)
for i in range(m):
    b.append(0)
for i in range(n):
    l=list(map(int,input().split()))
    for j in range(m):
        a[i]=a[i]+l[j]
        b[j]=b[j]+l[j]
for i in range(n):   
    ans=ans+2**a[i]-1+2**(m-a[i])-1
for i in range(m):
    ans=ans+2**b[i]-1+2**(n-b[i])-1
ans=ans-n*m
print(ans)