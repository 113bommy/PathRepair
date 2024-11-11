l=list(input())
a=b=0
for i in l:
	if i=='a':
		a+=1
	if i!='a':
		b+=1
if a>b:
	print(a+b)
else:
	print(2*a-1)