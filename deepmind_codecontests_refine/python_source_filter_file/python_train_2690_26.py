from itertools import*
H,W=map(int,input().split())
C=[list(map(int,input().split()))for _ in range(10)]
for i,j,k in product(range(10),repeat=3):C[i][j]=min(C[i][j],C[i][k]+C[k][j])
l=[0]*11
for _ in range(H):
 for i in input().split():l[int(i)]+=1
print(sum(C[i][1]*v for i,v in enumerate(l[:-1])))