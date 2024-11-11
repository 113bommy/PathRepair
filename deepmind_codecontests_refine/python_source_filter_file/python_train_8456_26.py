for ttt in range(int(input())):
	n = int(input())
#	l = list(map(int, input().split()))
	#n, m = map(int, input().split())
	t = 0
	k = 0
	while True:
		t *= 2
		t += 1
		k += 1
		if n % t == 0:
			break
	print(n // (2 ** k - 1))