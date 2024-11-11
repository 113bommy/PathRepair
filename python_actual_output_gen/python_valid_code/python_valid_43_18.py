n, k = [int(i) for i in input().split()]
if k == 0 : print(0)
elif n >= k : print(1)
else :
	if k % n == 0:
		print(n // k)
	else :
		print(n // k + 1)