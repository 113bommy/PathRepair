from fractions import Fraction
a,b,c,d=map(int,input().split())
if c/a>d/b:
	d=d*(a/c)
	c=a
	k=b-d
	e=((k)/b)
elif c/a<d/b:
	c=c*(b/d)
	d=b
	k=a-c
	e=((k)/a)
else:
	print("0")
	exit()
print(Fraction(e).limit_denominator())