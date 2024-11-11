r=input()
ur=input()
rp=r.count("+")
rn=r.count("-")
urp=ur.count("+")
urn=ur.count("-")
x=rp-urp
n=(rp+rn)-(urp+urn)
if rp<urp or rn<urn:
	print(0)
else:
	p=1
	q=1
	for i in range(n,n-x,-1):
		p*=i
	for j in range(1,x+1):
		q*+j
	y=p//q	
	z=1<<n
	print("{0:.12f}".format(y/z))