def solve(n):
	if n < 4:
		print(-1)
		return
	if n&1 == 0:
		a = n-1
	else:
		a = n
	for i in range(a,0,-2):
		print(i,end =" ")
	print("4 2",end = " ")
	for i in range(6,n,2):
		print(i,end = " ")
	print()
t = int(input())
for _ in range(t):
	n = int(input())
	solve(n)
		