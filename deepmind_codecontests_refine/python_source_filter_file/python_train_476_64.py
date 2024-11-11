s, v1, v2, t1, t2= input().split()
s = int(s)
v1 = int(v1)
v2 = int(v2)
t1 = int(t1)
t2 = int(t2)
x = s*v1 + 2*t1
y = s*v2 + 2*t2
if x<y:
	print("FIRST")
elif x>y:
	print("second")
else:
	print("friendship")