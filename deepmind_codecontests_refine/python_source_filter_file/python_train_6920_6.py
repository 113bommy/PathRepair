s=input().split()
n=int(s[0])
m=int(s[1])
x=[n,m]

x.sort()
if n+m>2 and n>0 and m>0:
	if x[1]//x[0]>=x[0]:
		print(x[0])
	else:
		print((n+m)//3)
else:
	print(0)
