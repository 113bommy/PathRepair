t = int(input())

for i in range(t):
	n = int(input())
	s = input()
	if (n<8):
		print("NO")
		continue
	b = False
	for i in range(0, n-10):
		if s[i]=='8':
			b = True
			break
	if b:
		print("YES")
	else:
		print("NO")