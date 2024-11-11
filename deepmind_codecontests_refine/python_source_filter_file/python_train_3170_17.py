a=0
b=0
s=1
n=1

n=int(input())
for i in range(n):
	st=input()
	if s==1:
		s=st
		a+=1
	elif n==1 and st!=s:
		n=st
		b+=1
	if st==s:
		a+=1
	else:
		b+=1
if a>b:
	print(s)
else:
	print(n)