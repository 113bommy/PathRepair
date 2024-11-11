t = int(input())
for i in range(t):
	n = int(input())
	if n == 1:
		print(-1)
	else:
		s = "9"*(n-1)
		s += "8"
		print(s)