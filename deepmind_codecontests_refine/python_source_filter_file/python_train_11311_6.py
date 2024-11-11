a, b = input().split()
a, b = int(a), int(b)

while (a!=0 and b!=0):
	if (a>2*b):
		a=a-2*b
	elif b>2*a:
		b=b-2*a
	else:
		break
print(a, b)