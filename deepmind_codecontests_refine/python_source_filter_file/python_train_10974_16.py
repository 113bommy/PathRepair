n = int(input())

print(n*n//2)

for i in range(n):
	s = ""
	for j in range(n):
		if(i % 2 == 0):
			if(j % 2 == 0):
				s += "c"
			else:
				s += "."
		else:
			if(j % 2 == 0):
				s += "."
			else:
				s += "c"
	print(s)