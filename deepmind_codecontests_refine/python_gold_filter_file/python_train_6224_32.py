p=d=2019
z=[0]*p
for i,j in enumerate(input()[::-1]):
	d+=int(j)*pow(10,i,p)
	z[d%p]+=1
r=z[0]
for i in z:
	r+=i*(i-1)//2
print(r)