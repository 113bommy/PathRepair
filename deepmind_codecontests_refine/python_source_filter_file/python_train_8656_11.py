t = int(input())
for i in range(t):
	n = int(input())
	s = input()
	zostalo = n
	i = 0
	c = 1
	while True:
		if zostalo < 11:
			break
		if s[i] == '8':
			print("YES")
			c = 0
		zostalo -= 1
		i += 1
	if c == 1:
		print("NO")
		