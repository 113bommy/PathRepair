t = int(input())
for i in range(0, t):
	n, s, t = map(int, input().split())
	c = abs(n-s-t)
	print(max(t-c,t-s)+1)