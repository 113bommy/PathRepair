for _ in range(int(input())):
	s =input()
	if(s.count('10')==0 and s.count('01')==0): print('NET')
	else:
		c=0
		while(s.count('10')>0 or s.count('01')>0):
			if(s.count('10')>0):
				s=s.replace("10","",1)
				c+=1
			if(s.count('01')>0):
				s=s.replace("01","",1)
				c+=1
		print("DA" if c%2==1 else "NET")