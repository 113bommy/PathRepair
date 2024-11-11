def el_round_4_C():
	listA = input().split(" ")
	xa=int(listA[0])
	ya=int(listA[1])
	listB = input().split(" ")
	xb = int(listB[0])
	yb = int(listB[1])
	listC = input().split(" ")
	xc = int(listC[0])
	yc = int(listC[1])
	listx=[]
	listy=[]
	listx.append(xa)
	listx.append(xb)
	listx.append(xc)
	listy.append(ya)
	listy.append(yb)
	listy.append(yc)

	listx.sort()
	listy.sort()
	print(listx[2]-listx[0]+listy[2]-listy[0]+1)
	if(xa==listx[0]):
		x=xa
		y=ya
	elif(xb==listx[0]):
		x = xb
		y = yb
	elif(xc==listx[0]):
		x = xc
		y = yc

	while(x<listx[1]):
		print(str(x)+" "+str(y))
		x+=1

	for y in range(listy[0],listy[2]+1):
		print(str(x) + " " + str(y))

	if(listx[2]==xa):
		y=ya
	elif (listx[2] == xb):
		y = yb
	elif (listx[2] == xc):
		y = yc
	if(listx[2]>listx[1]):
		for x in range(listx[1]+1,listx[2]+1):
			print(str(x)+" "+str(y))
el_round_4_C()