n,m=map(int,input().split())
mat=[]
for _ in range(n):
    l1=[]
    l=input()
    for i in l:
        l1.append(i)
    mat.append(l1)
#print(mat)
r1=0
r2=0
c1=0
c2=0
for i in range(n):
    if(mat[i].count('*')>0):
        r1=i
        break
for i in range(n-1,-1,-1):
    if(mat[i].count('*')>0):
        r2=i
        break
#print(r1,r2)
for i in range(m):
    for j in range(n):
        if(mat[j][i]=='*'):
            c1=i
            break
for i in range(m-1,-1,-1):
    for j in range(n):
        if(mat[j][i]=='*'):
            c2=i
            break
print(r1,r2,c1,c2)
for i in range(r1,r2+1):
    for j in range(c2,c1+1):
        print(mat[i][j],end='')
    print()
        