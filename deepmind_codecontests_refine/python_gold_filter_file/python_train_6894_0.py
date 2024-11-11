t=int(input())

for i in range(t):
	n,m=map(int,input().split())
	if n<6:print('NO')
	elif n%m==0 and m>2:print('YES')
	else:print("NO")