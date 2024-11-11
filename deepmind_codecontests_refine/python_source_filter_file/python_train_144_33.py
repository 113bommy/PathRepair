d, c = map(int, input().split())
m = 0
ds = list(map(int, input().split()))
for i in range(d-1):
	m = max(ds[i] - ds[i+1], m)
if (m != 0):
	print(m - c)
else:
	print(m)