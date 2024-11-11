s = input()
a = s.count('4')
b = s.count('7')
if a+b == 0:
	print(-1)
if a>=b:
	print(4)
else:
	print(7)
