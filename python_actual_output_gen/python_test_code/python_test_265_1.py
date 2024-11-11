n = int(input())
count1, count2,count3,count4 = 0,0,0,0
for i in range(n):
	t,x,y = map(int,input().split())
	if t==1:
		count1 = count1+x
		count2 = count2+y
	else:
		count3 = count1+x
		count4 = count2+y
if count1>=count2:
	print("LIVE")
else:
	print("DEAD")
if count3>=count4:
	print("LIVE")
else:
	print("DEAD")
