n,k=map(int,input().split())
t=[True]*(n+1)
x=0
p=0
s=list()
for i in range(n+1):
    if t[i] and i>=2:
        if any(f==i for f in s):
            x+=1
        if p!=0:
            s.append(i+p+1)
        p=i
        for j in range(i,n+1,i):
            if t[j]:
                 t[j]=False

if x>=k:
    print('YES')
else:
    print('NO')
        
