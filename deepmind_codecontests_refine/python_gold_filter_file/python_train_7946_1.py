st1= input()
t=st1.split(" ")
n=int(t[0])
t1=int(t[1])
t2=int(t[2])
k=int(t[3])
inp=[]
out=[]
rak=[]
for i in range(n):
	st2= input()
	st=st2.split(" ")
	a=int(st[0])
	b=int(st[1])
	z1=((t1*a)*(100-k)/100)+(t2*b)
	z2=((t1*b)*(100-k)/100)+(t2*a)
	if(z1>z2):
		out.append(z1)
	else:
		out.append(z2)
for i in range(n):
	rk=0
	for j in range(n):
		if(out[j]>out[i])or((out[j]==out[i])and(j<=i)):
			rk+=1
	rak.append(rk)
	
for i in range(n):
	for j in range(n):
		if(rak[j]==i+1):
			o=str("%.2f" % out[j])
			print(str(j+1)+" "+o[:o.find(".")+3])