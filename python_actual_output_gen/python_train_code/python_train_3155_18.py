test = int(input())
for t in range(test):
	x1,y1,x2,y2 = map(int, input().split())
	ans = abs(x1-x2) + abs(y1-y2)
	if abs(x1-x2)==0 or abs(y1-y2)==0:
		print(ans)
	else:
		print(2*ans)