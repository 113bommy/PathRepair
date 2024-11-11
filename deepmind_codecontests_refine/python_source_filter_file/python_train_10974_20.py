n = int(input())

print((n+1)//2)

for i in range(n):
	s = ""
	for j in range(n):
		if(i % 2 == 0):
			if(j % 2 == 0):
				s += "C"
			else:
				s += "."
		else:
			if(j % 2 == 0):
				s += "."
			else:
				s += "C"
	print(s)