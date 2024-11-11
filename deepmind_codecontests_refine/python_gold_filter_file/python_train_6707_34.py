z=input()
a,b,c,d=0,0,0,0
for x in z:
	if x=='n':
		a=a+1
	if x=='i':
		b=b+1
	if x=='t':
		c=c+1
	if x=='e':
		d=d+1
t=0
k=min(b,c)
if k!=0:
	for i in range(k):
		if (a+k-i-1)//(k-i)>=3 and d//(k-i)>=3:
			print(k-i)
			t=t+1
			break
	if t==0:
		print(t)
else:
	print(0)
