def mayor(a,b):
	if a>=b:
		x=a
	else:
		x=b
	return b
a=int(input())
b=int(input())
c=int(input())
d=a+(b*c)
e=a*(b+c)
f=a*b*c
g=(a+b)*c
h=a+b+c
m=mayor(mayor(d,e),mayor(f,g))
n=mayor(m,h)
print(n)

