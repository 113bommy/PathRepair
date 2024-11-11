def solve(xa,ya1,xa1,ya2,xb1,yb1,xb2,yb2):
	if xb2<xa1 or xb1>xa2 or yb2<ya1 or yb1>yb2:
		print("NO")
	else:
		print("YES")


while True:
	try:
		xa,ya1,xa1,ya2,xb1,yb1,xb2,yb2=map(float,input().split())
		solve(xa,ya1,xa1,ya2,xb1,yb1,xb2,yb2)
	except EOFError:
		break