N,T=map(int,input().split())
res=1001

for _ in range(N):
	c,t=map(int,input().split())
	if t<=T:
		res=min(res,c)

if res=1001:
	print("TLE")
else:
	print(res)