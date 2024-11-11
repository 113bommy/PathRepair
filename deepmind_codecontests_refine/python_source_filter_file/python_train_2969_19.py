x,y,s=input().split()
x=int(x)
cnt=0
if s=="month":
	if x==31:
		cnt=7
	elif x==30:
		cnt=11
	else:
		cnt=12
else:
	if x==6:
		cnt=53
	else:
		cnt=52
print(cnt)
