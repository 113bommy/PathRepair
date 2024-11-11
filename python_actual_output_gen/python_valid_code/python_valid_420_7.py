def z(s,l):
	for i in range(n-1):
		r=l+a[i+1]
		if r*l>=0:
			if l<=0:
				s+=1-r
				r=1
			else:
				s+=1+r
				r=-1
		l=r
	return s

n=int(input())
a=list(map(int,input().split()))
s1=0
l1=a[0]
if a[0]<=0:
	s1=1-a[0]
	l1=1
s2=0
l2=a[0]
if a[0]>=0:
	s1=a[0]-1
	l1=-1
print(min(z(s1,l1),z(s2,l2)))