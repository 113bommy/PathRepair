n=int(input())
s=input()

c=int((n-11)/2)

c1=0
c2=0

t=0

for i in range(len(s)):
	if s[i]=='8':
		c1=c1+1
	else:
		c2=c2+1

	if c1==c:
		if c2<=c:
			t=1
			break
if t==0:
	print("NO")
else:
	print("YES")				
				


