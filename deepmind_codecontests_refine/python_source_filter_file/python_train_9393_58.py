t = int(input())
for i in range(t):
	n = int(input())
	if n == 1:
		print(-1)
	else:
		s = "2"*(n-1)
		s += "7"
		print(s)