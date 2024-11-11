N = int(input())
a = list(map(int,input().split()))

a_max = max(a)
max_idx = a.index(a_max)
a_min = min(a)
min_idx = a.index(a_min)

ans = ''
if abs(a_max) >= abs(a_min):
	ans += '{}\n'.format(2 * N - 1)
	for i in range(N):
		ans += '{} {}\n'.format(max_idx + 1, i + 1)
	for i in range(1, N):
		ans += '{} {}\n'.format(i, i + 1)
else:
	ans += '{}'.format(2 * N - 1)
	for i in range(N):
		ans += '{} {}\n'.format(min_idx + 1, i + 1)
	for i in range(N, 1, -1):
		ans += '{} {}\n'.format(i, i - 1)

print(ans,end="")