n,x,y = map(int,input().split())
s = input()

count = 0 
if(s[0] == '1'):
	tp = -1
else:
	tp = 0
	count = 1
for i in range(1,n):
	if s[i] == '0':
		if tp == -1:
			tp = 0
			count += 1
	else:
		if tp == 0:
			tp = -1
if  x >= y:
	print(count*y)
else:
	if count >= 2:
		print((count -1)*x + y)
	elif count == 1 :
		print(x)
	else:
		print(0)

