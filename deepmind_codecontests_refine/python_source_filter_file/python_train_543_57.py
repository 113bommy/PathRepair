def f(n):
	return 2*n + 2*(n - 2);


t = int(input())
while(t):
	n = int(input())
	moves = 0
	if(n == 0):
		print(0)
	elif(n == 3):
		print(8)
	else:
		moves = 8
		k = 2
		i = 5
		while(i <= n):
			moves += k * f(i)
			k+=1
			i+=2
		print(moves)
	t -= 1