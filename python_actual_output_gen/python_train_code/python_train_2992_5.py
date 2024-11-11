def Fedor(l,k):
	count=0
	for i in range(len(l)-1):
		if sum(int(x) for x in list("{0:b}".format(abs(l[i]-l[len(l)-1]))))<=k:
			count+=1
	print(count)

d=input()
l=[]
n=int(d.split()[0])
m=int(d.split()[1])
k=int(d.split()[2])
for i in range(m+1):
	d=input()
	l.append(int(d))

Fedor(l,k)