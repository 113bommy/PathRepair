t=int(input())
while(t):
	t=t-1
	r=input()
	fl=0
	fu=0
	fd=0
	r1=""
	for i in r:
		if i.isupper():
			fu=fu+1
		elif i.islower():
			fl=fl+1
		else:
			fd=fd+1
	if (fu and fd and fu):
		print(r)
		continue
	if (fu==0 and fl==0):
		print ("Aa"+r[2:])
		continue
	if (fd==0 and fl==0):
		print ("1a"+r[2:])
		continue
	if (fu==0 and fd==0):
		print ("1A"+r[2:])
		continue
	if (fu==0):
		f=1
		r1=""
		for i in r:
			if (i.islower() and fl>1 and f):
				r1=r1+"A"
				f=0
			elif(i.islower()!=1 and fd>1 and f):
				r1=r1+"A"
				f=0
			else:
				r1=r1+i
		print (r1)
		continue
	if (fl==0):
		f=1
		r1=""
		for i in r:
			if (i.isupper() and fu>1 and f):
				r1=r1+"a"
				f=0
			elif(i.isupper()!=1 and fd>1 and f):
				r1=r1+"a"
				f=0
			else:
				r1=r1+i
		print (r1)
		continue
	if (fd==0):
		f=1
		r1=""
		for i in r:
			if (i.islower() and fl>1 and f):
				r1=r1+"1"
				f=0
			elif(i.isupper() and fu>1 and f):
				r1=r1+"1"
				f=0
			else:
				r1=r1+i
		print (r1)
		continue