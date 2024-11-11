t=int(input())

for i in range(t):
	n,m=map(int,input().split())
	if n<6:print('NO')
	elif n%2==0 and m==n//2:print("YES")
	else:print("NO")