k = int(input())
for i in range(0, k):
	n, s, t = map(int, input().split())
	c = abs(n-s-t)
	print(max(t-c,s-c)+1)