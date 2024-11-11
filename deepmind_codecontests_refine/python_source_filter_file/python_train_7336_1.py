s=input()
a=[]
t=input()
for i in range(len(s)):
	a.append(int(ord(s[i])))
bb=a.copy()
c=1
for i in range(len(s)-1,-1,-1):
	if(a[i]+c>122):
		bb[i]=chr(65)
	else:
		bb[i]=chr(a[i]+c)
		c=0
if(c==1):
	print("No such string")
else:
	ans=''.join(bb)
	if(ans<t):
		print(ans)
	else:
		print("No such string")