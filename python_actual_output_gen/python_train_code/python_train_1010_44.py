n, k = map(int, input().split())

first = min(1, n - k)
second = min(2 * k, n - k)

if k == 0:
	print('0 0')
print('{} {}'.format(first, second))