t = int(input())


for r in range(t):
	n, k = map(int, input().split())
	print(k*(n/k) + min(k/2, n%k))