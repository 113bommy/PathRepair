a,b,c,d=map(int,input().split())
p=[[0]*(d+2)for i in range(c+1)]
p[a][b]=1
m=998244353
for i in range(a,c+1):
 for j in range(b,d+1):p[i][j]+=(j*p[i-1][j]+i*p[i][j-1]-(i-1)*(j-1)*p[i-1][j-1])%m;p[i][j]%=m
print(p[-1][-2]%m)