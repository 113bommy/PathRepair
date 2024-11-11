n,k=map(int,input().split())
from math import ceil 
if k>ceil(n/2):
    print('NO')
    exit()
print('YES')
mat=[['S' for i in range(n)]for i in range(n)]
for i in range(n):
    for j in range(n):
        if i%2==j%2 and k:
            k=k-1 
            mat[i][j]='L'
for i in range(n):
    print(*mat[i],sep='')