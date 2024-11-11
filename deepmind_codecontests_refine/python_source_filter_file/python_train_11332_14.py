n,m=map(int,input().split())
a=[input()for _ in range(n)]
b=[input()for _ in range(m)]
x=n-~-m
C=0
for i in range(x):
    for j in range(x):
        c=0
        for k in range(m):
            if a[i+k][j:j+x]==b[k]:
                c+=1
        if c==m:
            C+=1
print('YNeos'[C<1::2])