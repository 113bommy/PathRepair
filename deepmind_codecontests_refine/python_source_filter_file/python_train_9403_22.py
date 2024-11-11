import sys
i=-1
for line in sys.stdin:
	i+=1
	if i==0:
		s=line.split(' ')
		n=int(s[0])
		k=int(s[1])
	elif i==1:
		s=line.split(' ')
		pts=[int(x) for x in s]
	else:
		break
k-=1
lm=pts[k]
if lm > 0:
	p=0
	while p+k<n and pts[p+k]>=lm:
		p+=1
	print(p+k)
else:
	p=0
	while k-p>=0 and pts[p-k]==0:
		p+=1
	print(k-p+1)
