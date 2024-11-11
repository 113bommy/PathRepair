import sys
inp = sys.stdin.readline
ans = ""

for _ in range(int(inp())):
	n = int(inp())
	arr  = list(map(int, inp().split()))
	arr.sort(reverse = True)
	print(arr)
	maxi = 0
	for i, elem in enumerate(arr):
		if (i+1) <= elem:
			maxi = max(maxi, i+1)
	ans += str(maxi)+"\n"
print(ans)
