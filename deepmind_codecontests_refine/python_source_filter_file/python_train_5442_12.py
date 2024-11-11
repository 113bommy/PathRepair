t = int(input())
for _ in range(t):
	n = int(input())
	a = input()
	if(n == 1):
		if(int(a[0]) % 2):
			print(1)
		else:
			print(2)
		continue
	if(n%2):
		ans = False

		for i in range(1, n, 2):
			if(int(a[i]) % 2 == 0):
				ans = True
				break
		if(ans):
			print(1)
		else:
			print(2)
	else:
		ans = False
		for i in range(0, n, 2):
			if(int(a[i]) % 2 ):
				ans = True
				break
		if(ans):
			print(1)
		else:
			print(2)

	# Raze odd 1
	# breach even 2 