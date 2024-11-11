n, k = list(map(lambda k: int(k), input().split()))
a = list(map(lambda k: int(k), input().split()))

# ith allows continuous of a_i hour
# segment of length k, n buckets.
min_hour = n
# print(a)
for ai in a:
	# print(k, ai)
	if k % ai == 0:

		min_hour = min(min_hour, k // ai)
print(min_hour)