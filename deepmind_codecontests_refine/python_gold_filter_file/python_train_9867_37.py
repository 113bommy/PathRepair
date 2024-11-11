a,b,c,d=map(int,input().split());m=998244353;x=range(c+d);D=[[0]*6011for _ in[0]*6011];D[a][b]=1
for i in x:
 for j in x:D[i+1][j+1]+=(D[i+1][j]*(i+1)+D[i][j+1]*(j+1)-D[i][j]*i*j)%m
print(D[c][d])