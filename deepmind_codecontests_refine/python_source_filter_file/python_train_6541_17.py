n,c=map(int,input().split())
l=[list(map(int,input().split())) for i in range(n)]
L=[[0 for i in range(10**5)] for i in range(c)]
for i in range(n):
  for j in range(l[i][0],l[i][1]+1):
    L[l[i][2]-1][j]=1
ans=[]
for i in range(10**5):
  ct=0
  for j in range(c):
    ct+=L[j][i]
    ans.append(ct)
print(max(ans))