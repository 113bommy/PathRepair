for i in range(int(input())):
	n, k = [int(w) for w in input().split()]
	ans = 0
	while n != 0 :
		ans += n % k + 1
		n = (n - n%k) // k
	print(ans-1)
	