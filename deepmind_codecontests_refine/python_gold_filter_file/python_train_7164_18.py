n,m,q=map(int,input().split())
b=[501*[0]for i in range(501)]
for i in range(m):
  r,l=map(int,input().split())
  b[r][l]+=1
for i in range(501):
  for j in range(1,501):b[i][j]+=b[i][j-1]
for i in range(1,501):
  for j in range(501):b[i][j]+=b[i-1][j]
for i in range(q):
  l,r=map(int,input().split())
  print(b[r][r]-b[l-1][r]-b[r][l-1]+b[l-1][l-1])
#  >>優しい言葉を投げかければそのコードはACする<<