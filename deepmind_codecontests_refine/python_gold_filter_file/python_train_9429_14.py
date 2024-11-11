n=input()
li=input().split()
li=[int(x) for x in li]
li=sorted(li)
a=li[0]
b=li[1]
f=0
for i in range(2,len(li)):
	if (a+b>li[i]):
		f=1
		break
	a=li[i-1]
	b=li[i]
if f:
	print('YES')
else:
	print('NO')