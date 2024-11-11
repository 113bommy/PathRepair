n = int( input() )

Q = 0
P = 0
Df = 0
Db = 0
l=[]
for a in range(n):
	x = int(input())
	if a==n-1:
		l.append(x)
	if x==0 or a==n-1:
		insQ=True
		if l!=[]:
			Q = max(l)
		for i in l:
			if i==Q and insQ:
				print("pushQueue")
				insQ=False
			elif i>P and P<=Df:
				print("pushStack")
				P=i
			elif i>Df and Df<=P:
				print("pushFront")
				Df=i
			else:	
				print("pushBack")
		
		#estrazione
		if a!=n-1 or x==0:
			cnt=0
			s = ""
			if Q!=0: 
				cnt+=1
				s+=" popQueue"
			if P!=0: 
				cnt+=1
				s+=" popStack"
			if Df!=0: 
				cnt+=1
				s+=" popFront"
			
			print(	str(cnt) + s )
		
		Q=0
		P=0
		Df=0
		Db=0
		l=[]
		
	else:
		l.append(x)
		
	
