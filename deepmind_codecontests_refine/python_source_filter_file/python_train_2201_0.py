t1 = input()
t2 = input()
if int(t2[:2]) - int(t1[:2]) > 1:
	if int(t1[3:]) == int(t2[3:]):
		r1 = (int(t1[:2])+int(t2[:2]))//2

		if (int(t1[:2])+int(t2[:2]))%2==1:
			r2=int(t1[3:])+30
		else:
			r2=int(t1[3:])
		if r2>=60:
			r1=r1+1
			r2 = r2 - 60
			
		if r2//10 == 0:
			k = "0"+str(r2)
		else:
			k = str(r2)
		if r1//10==0:
			l = "0"+str(r1)
		else:
			l = str(r1)

		print(l+":"+k)
	elif int(t2[3:]) > int(t1[3:]):
		r1 = (int(t1[:2])+int(t2[:2]))//2
		r2 = (int(t1[3:])+int(t2[3:]))//2
		if (int(t1[:2])+int(t2[:2]))%2 == 1:
			r2 =r2+30
		if r2 >= 60:
			r1 = r1 + 1
			r2 = r2 - 60
		if r2//10 == 0:
			k = "0" + str(r2)
		else:
			k = str(r2)
		if r1//10 == 0:
			l = "0" + str(r1)
		else:
			l = str(r1)
		print(l+":"+k)
	elif int(t2[3:]) < int(t1[3:]):
		r2 = (60 + int(t2[3:]) - int(t1[3:]))//2
		r1 = (int(t1[:2])+int(t1[:2]))//2
		if r2//10 == 0:
			k = "0"+str(r2)
		else:
			k = str(r2)

		print(str(r1-1)+":"+k)
elif int(t2[:2]) - int(t1[:2]) == 1:
	if int(t1[3:]) >= int(t2[3:]):
		r2 = (60-int(t1[3:])+int(t2[3:]))//2
		k = (int(t1[3:])+r2)
		if int(t1[3:]) + 30 < 60:
			k = (int(t1[3:])+r2)
			if k//10 == 0:
				k = "0" + str(k)
			else:
				k = str(k)
			print(t1[:2]+":"+k)			
		elif int(t1[3:]) + 30 > 60:
			k = (int(t2[3:])-r2)
			if k//10 == 0:
				k = "0" + str(k)
			else:
				k = str(k)
			print(t2[:2]+":"+k)
	elif int(t1[3:]) < int(t2[3:]):
		r2 = (60 + int(t2[3:]) - int(t1[3:]))//2
		if int(t1[3:]) + 30 > 60:
			print(t2[:2]+":"+str(int(t2[3:])-r2))
		elif int(t1[:2]) + 30 < 60:
			print(t1[:2]+":"+str(int(t1[3:])+r2))
else:
	r2 = (int(t2[3:])+int(t1[3:]))//2
	if r2//10 == 0:
		k = "0"+str(r2)
	else:
		k = str(r2)
	print((t1[:2])+":"+k)

