a=int(input())
b=int(input())
c=int(input())
ss=0
for i in range(0,6):
	if a<=b/2 and a<=c/4:
		ss=1
		break
	else:
		a-=1
if ss==1:
	print(a*1+a*2+a*4)
else:
	print(0)