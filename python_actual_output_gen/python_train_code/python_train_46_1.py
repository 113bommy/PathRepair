def solve():
	x,y=map(int,input().split())
	dc={}
	s=list(map(int,input().split()))
	z=list(map(int,input().split()))

	for n in z:
		dc[n]=1

	for n in s:
		if n in dc: 
			print('YES')
			print(n)

			return
	print('NO')


for _ in range(int(input())):
	
	solve()