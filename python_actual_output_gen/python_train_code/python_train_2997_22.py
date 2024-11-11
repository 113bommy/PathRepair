x1,y1,x2,y2 = map(int,input().split())
a,b = map(int,input().split())
if (abs(x1-x2)//a -abs(y2-y1)//b)%2 == 0 and abs(x1-x2)%a == abs(y2-y1)%b:
	print("Yes")
else:
	print("No")