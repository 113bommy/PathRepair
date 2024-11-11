a, b, c, d = map(int, input().split())
x = a/b
y = c/d

s = 0
for i in range(100):
	if i == 0:
		s += x
	else:
		s += ((1-x)**i)*((1-y)**i)*x
print (s)