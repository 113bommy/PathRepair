n=int(input())
if n==1:
	print(1)
else:
	k=n
	a=0
	for i in range(1,n):
		if n%i==0:
			t=n//i
			r=abs(t-i)
			if r<k:
				k=r
				a=i
	b=n//a
	print(a,b)