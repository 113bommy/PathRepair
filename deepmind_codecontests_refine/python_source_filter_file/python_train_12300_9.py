from bisect import bisect_left
n, m, ta, tb, k = map(int, input().strip().split())
a = list(map(int, input().strip().split()))
b = list(map(int, input().strip().split()))
if k >= min(n, m):
	exit(print(-1))
ind_a = k
max_time = 0
while ind_a > 0:
	ind_b = bisect_left(b, a[ind_a]+ta) + (k-ind_a)
	if ind_b >= m:
		exit(print(-1))
	curr_time = b[ind_b] + tb
	max_time = max(max_time, curr_time)
	ind_a -= 1
print(max_time)
