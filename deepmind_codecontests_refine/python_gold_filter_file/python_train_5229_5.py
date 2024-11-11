t = int(input())


for r in range(t):
	n, k = map(int, input().split())
	print(k*int(n/k) + min(int(k/2), n%k))