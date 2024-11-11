l=list(input())
r=l.count("7")
y=l.count("4")
if r>0 and y>0:
	if r>y:
		print("7")
	else:
		print("4")
else:
	print(-1)