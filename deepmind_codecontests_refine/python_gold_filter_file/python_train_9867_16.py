a,b,c,d=map(int,input().split());m=998244353;D=[[0]*(d+1)for _ in range(c+1)];D[a][b]=1
for i in range(c):
 for j in range(d):D[i+1][j+1]+=(D[i+1][j]*(i+1)+D[i][j+1]*(j+1)-D[i][j]*i*j)%m
print(D[c][d])