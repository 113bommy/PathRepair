I=lambda:[*map(int,input().split())]
R=range;m=min;N,M,K=I();r=R(N)
if K&1:
	for _ in r:print(*[-1]*M)
	exit()
A=[I()for _ in r]
B=[I()for _ in R(N-1)]
X=[M*[0]for _ in r]
for k in R(1,K//2+1):
	Y=[M*[9**9]for _ in r]
	for i in r:
		for j in R(M):
			if i:Y[i][j]=X[i-1][j]+2*B[i-1][j]
			if i<N-1:Y[i][j]=m(Y[i][j],X[i+1][j]+2*B[i][j])
			if j:Y[i][j]=m(Y[i][j],X[i][j-1]+2*A[i][j-1])
			if j<M-1:Y[i][j]=m(Y[i][j],X[i][j+1]+2*A[i][j])

for x in X:print(*x)