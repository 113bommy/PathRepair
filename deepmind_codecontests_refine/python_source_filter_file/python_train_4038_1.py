n,m,x=map(int,input().split())
CA=[list(map(int,input().split())) for _ in range(n)]

res=10**7

for i in range(2**n-1):
	money=0
	under=[0]*m
	
	for j in range(n):
		if i>>j&1:
			money+=CA[j][0]
			for k in range(m):
				under[k]+=CA[j][k+1]
		
		if min(under)>=x:
			res=min(res,money)

if res==10**7:
	print("-1")
else:
	print(res)	