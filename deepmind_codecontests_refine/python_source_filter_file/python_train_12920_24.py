cp=[chr(n) for n in range(ord('A'),ord('Z')+1)]
sm=[chr(n) for n in range(ord('a'),ord('z')+1)]
nm=[chr(n) for n in range(ord('1'),ord('9')+1)]
for _ in range(int(input())):
	sk=[n for n in input()]
	c=0
	s=0
	n=0
	for k in sk:
		if k in cp:
			c+=1
		elif k in sm:
			s+=1
		elif k in nm:
			n+=1
	if 0 in [c,s,n]:
		if n==0 and s==0:
			sk[0]='a'
			sk[1]='5'
		elif n==0 and c==0:
			sk[0:2]=['A','5']
		elif c==0 and s==0:
			sk[0:2]=['A','a']
		elif c==0:
			if s!=1:
				for n in range(len(sk)):
					if sk[n] in sm:
						sk[n]='A'
						break
			else:
				for n in range(len(sk)):
					if sk[n] in nm:
						sk[n]='A'
						break
		elif s==0:
			if c!=1:
				for n in range(len(sk)):
					if sk[n] in cp:
						sk[n]='a'	
						break
			else:
				for n in range(len(sk)):
					if sk[n] in nm:
						sk[n]='a'
						break
		elif n==0:
			if c!=1:
				for n in range(len(sk)):
					if sk[n] in cp:
						sk[n]='6'
						break
			else:
				for n in range(len(sk)):
					if sk[n] in sm:
						sk[n]='6'
						break
		
	for n in sk:
		print(n,end='')
	print()
	
						
					
			
				
			
	