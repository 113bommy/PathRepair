for _ in range(int(input())):
	x,y = map(int, input().split())
	ans = 0
	for i in range(1,10):
		a = '9'*i
		if y>int(a):
			ans +=1
	print(ans*x)

