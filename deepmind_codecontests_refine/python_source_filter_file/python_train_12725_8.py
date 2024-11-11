X,Y,L,R=map(int,input().split())
R-=L-1
if(X*Y)&1:
	print(pow(R,X*Y,998244353))
else:
	print((pow(R,X*Y,998244353)+(R&1))*998244354,1//2%998244353)