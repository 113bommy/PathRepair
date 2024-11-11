n = int(input())
lis = list(map(int,input().split()))
mat=[[lis[i],i] for i in range(n)]
mat.sort()
has=[0]*(4*101050)
for i in range(n):
    aa=mat[i][0]-mat[i][1]
#    print(aa)
    has[aa]+=mat[i][0]
print(max(has))
#print(mat)

