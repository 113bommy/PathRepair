perfectsquares=set(x**2 for x in range(10**5+1))
N=int(input())
array=[int(x) for x in input().split()]
squares,notsquares=[0,0]
squarelist=[]
notsquarelist=[]

for i in array:
	if i in perfectsquares:
		squares+=1
		squarelist.append(i)
	else:
		notsquares+=1
		notsquarelist.append(i)

toadd=[]
counter=0
if notsquares>squares:
	for i in notsquarelist:
		if i**(1/2)-float((i**(1/2)))//1<0.5:
			toadd.append(int(abs(i-(((i**(1/2))//1)**2))))
		else:
			toadd.append(int((abs(i-(((i**(1/2))//1)+1)**2))))
	toadd=sorted(toadd)
	counter=sum(toadd[:(notsquares-squares)//2])
elif squares>notsquares:
	for i in squarelist:
		if i==0:
			toadd.append(2)
		else:
			toadd.append(1)
	toadd=sorted(toadd)
	counter=sum(toadd[:(notsquares-squares)//2])
print(int(counter))