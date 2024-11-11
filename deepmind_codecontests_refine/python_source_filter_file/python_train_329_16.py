# Brute force 2: Keep subtracting it by the larger number

from decimal import Decimal

# HCF
def hcf(a,b):
	if a<b:
		return hcf(b,a)
	while b!=0:
		a,b=b,a%b
	return a

inpu = (input()).split(" ")
inp = [Decimal(x) for x in inpu]
n,p,w,d = inp[0], inp[1], inp[2], inp[3]


flag = 0

if p == 0:
	print("0 0 "+str(n))
else:
	f = hcf(w,d)
	if f != 1:
		rem = p%f
		if rem !=0:
			print(-1)
			flag = 1
		else:
			p = p//f
			d = d//f
			w = w//f


	if flag == 0:
		p = Decimal(p)
		w = Decimal(w)
		d = Decimal(d)
		i=0
		while(i<=w-1):
			k = p-i*d
			if k%w == 0 and ((k//w)+i<=n):
				x = k//w
				print(str(x)+" "+str(i)+" "+str(n-x-i))
				break
			i+=1
		else:
			print(-1)




