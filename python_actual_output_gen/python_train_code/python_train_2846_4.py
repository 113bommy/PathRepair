s = input()
a = input()
b = input()

def check(p):
	j = p.find(a)
	k = p.find(b, len(p)+j)
	return j != -1 and k != -1
f = check(s)
r = check(s[-1::-1])

if f and r:
	print("both")
elif f:
	print("forward")
elif r:
	print("backward")
else:
	print("fantasy")