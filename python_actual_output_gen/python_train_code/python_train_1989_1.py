n,m=map(int,input().split())
a,b=[],[]
for i in range(n):
    a.append(list(map(int,input().split())))
for i in range(n):
    b.append(list(map(int,input().split())))    

for i in range(n):
    for j in range(m):
        if a[i][j]>b[i][j]:
            a[i][j],b[i][j]=b[i][j],a[i][j]

def check(c):
    for i in range(n):
        for j in range(m):
            if i+1<n and c[i][j]>=c[i+1][j]:
                return False
            if j+1<m and c[i][j]>=c[i][j+1]:
                return False
    return True
if check(a) and check(b):
    print("Possile")
else:
    print("Impossible")