# n = int(input())
# a = list(map(int, input().split()))
# n, k = map(int, input().split())

MOD = 998244353

T = 1
# T = int(input())

for t in range(1, T + 1):
	# print('Case #' + str(t) + ': ', end = '')
	k = int(input())
	if k == 0:
		print(1, 1)
		print(1)
	else:
		print(3, 4)
		x = 1 << 18
		a = [[x + k, k, k, k], 
			 [x, k, k, x], 
			 [x, x, x + k, k]
			]
		for i in range(3):
			for j in range(4):
				print(a[i][j], end = ' ')
			print('')

