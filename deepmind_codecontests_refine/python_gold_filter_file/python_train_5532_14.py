x=str(input())
i=0
c=0
for i in range(0,len(x)):
	if x[i]!='4' and x[i]!='7':
		c=c+1
l=len(x)-c
y=str(l)
p=0
i=0
for i in range(0,len(y)):
	if y[i]!='4' and y[i]!='7':
		p=1
		break
if p==1:
	print("NO");
else:
	print("YES");