def mid(a, b, c):
	arr = [a, b, c]
	arr.sort()
	return arr[1]

a, b, c = map(int, input().split())
l = max(a, b, c)
m = min(a, b, c)
k = mid(a, b, c)
print(max(0, l - m - k))