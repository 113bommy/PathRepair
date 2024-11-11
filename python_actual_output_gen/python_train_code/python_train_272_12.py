for _ in range(int(input())):
	n,k = list(map(int, input().split()))
	ar = list(map(int, input().split()))
	max_n_1 = max(ar)
	ar_1 = list(map(lambda x: max_n_1 - x, ar))
	max_n_2 = max(ar)
	ar_2 = list(map(lambda x: max_n_2 - x, ar))
	if k%2 == 1:
		print(*ar_1)
	else:
		print(*ar_2)