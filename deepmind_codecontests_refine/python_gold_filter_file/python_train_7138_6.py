def f():
	n=int(input())
	d=0
	ok=True
	for i in range(n):
		l,direction = input().split()
		if direction == "North":
			d-=int(l)
		elif direction == "South":
			d+=int(l)
		elif d%20000==0 and l!=0:
			ok=False
			break
		if d<0 or d>20000:
			ok=False
			break
	if d!=0 or not ok:
		print("NO")
	else:
		print("YES")
f()