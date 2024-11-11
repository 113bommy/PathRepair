n,m=map(int,input().split())
mat=[]
for _ in range(n):
    l=list(input())
    mat.append(l)
mat1=[["B" if (i+j)%2==0 else "W" for i in range(m)] for j in range(n)]
for i in range(n):
    for j in range(m):
        if mat[i][j]=="-":
            mat1[i][j]="-"
for i in range(n):
    print(*mat1[i],sep="")
