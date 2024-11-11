p1,p2,p3,p4,a,b = map(int,input().split())
mini = min(p1,p2,p3,p4)
if a>mini:
	print(0)
elif b<mini:
	print(b-a+1)
else:
	print(mini-a)