a, b=input(), input()
la=len(a)
d=len(b)-la+1
c0, c1=  b[0:d].count('0'),  b[0:d].count('1')
s=c0 if a[0]=='1' else c1
for i in range(1, la):
	x=int(b[i+d-1])-int(b[i-1])
	c1+=x; c0=-x
	s+=c1 if a[i]=='0' else c0
print(s)
