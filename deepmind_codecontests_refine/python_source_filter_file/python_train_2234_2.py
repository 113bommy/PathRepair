n,m=map(int,input().split())
moves=[]
for i in range(0,n,2):
	if (i/2 + n-i)%m==0:
		moves.append(int(i/2+n-i))

try:
	print(min(moves))
except:
	print(-1)