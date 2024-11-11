for _ in range(int(input())):
	a,b,c,d = map(int,input().split())
	x,y,x1,y1,x2,y2 =  map(int,input().split())
	t = True
	if x2-x1>=1 and y2-y1>=1:
		if x==x1 and a-b>0 or b-a>x2-x1:
			t = False
		if y==y1 and c-d>0 or d-c>y2-y1:
			t = False
		if x==x2 and b-a>0 or a-b>x2-x1 :
			t = False
		if y==y2 and d-c>0 or c-d>y2-y1:
			t = False
		else:
			if a!=b:
				if a>b and a-b>x-x1 or b>a and b-a>x2-x:
					t = False
			if c!=d:
				if c>d and c-d>y-y1 or d>c and d-c>y2-y:
					t = False
	else:
		if x2==x1:
			if a>0 or b>0:
				t = False
			if y2!=y1:
				if y==y1 and c-d>0 or d-c>y2-y1:
					t = False
				elif y==y2 and d-c>0 or c-d>y2-y1:
					t = False
			elif y2==y1 and c>0 or d>0:
				t = False
		elif y2==y1 :
			if c>0 or d>0:
				t = False
			if x1!=x2:
				if x==x1 and a-b>0 or b-a>x2-x1:
					t = False
				if x==x2 and b-a>0 or a-b>x2-x1 :
					t = False
	if t:
		print("Yes")
	else:
		print('No')