n = int(input())
a = list(map(int,input().split()))
if n<=1:
	if a[0]==15:print("DOWN")
	elif a[0]==0:print("UP")
	else:print(-1)
else:
	if a[-1]-a[-2]>0:
		if a[-1]!=15:print("UP")
		else:print("DOWN")
	else:
		if a[-1]==0:print("UP")
		else:print("DOWN")