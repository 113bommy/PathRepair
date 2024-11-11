for i in range(int(input())): 
	s=list(input()) 
	mF='' 
	c1,cntB,cntS=0,0,0 
	l,u,c,k,stri,max=0,0,0,0,0,0 
	for j in range(len(s)): 
		if s[j]=='0' or s[j]=='1' or s[j]=='2' or s[j]=='3' or s[j]=='4' or s[j]=='5' or s[j]=='6' or s[j]=='7' or s[j]=='7' or s[j]=='8' or s[j]=='9': 
			c1+=1 
			l+=1 
			
			if max<cntB: 
				max=cntB 
				mF='B' 
				stri=j-cntB 
				
			if max<cntS: 
				mF='s' 
				max=cntS 
				stri=j-cntS 
				cntB,cntS=0,0 
				
		elif s[j].islower(): 
			u+=1 
			cntS+=1 
			
			if max<cntB: 
				mF='B' 
				max=cntB 
				stri=j-cntB 
				
			if max<c1: 
				max=c1 
				mF='1' 
				stri=j-c1 
				cntB,c1=0,0 
				
		else: 
			c+=1 
			cntB+=1 
			if max<cntS: 
				max=cntS 
				mF='s' 
				stri=j-cntS 
				
			if max<c1: 
				mF='1' 
				max=c1 
				stri=j-c1 
				cntS,c1=0,0 
	if max<cntS: 
		max=cntS 
		stri=len(s)-cntS 
		
	if max<c1: 
		max=c1 
		stri=len(s)-c1 
		
	if max<cntB: 
		max=cntB 
		stri=len(s)-cntB 
		
	if l==0 or u==0 or c==0: 
		sd=0 
		if l==0: 
			s[stri]='1' 
			sd+=1 
			
		if u==0: 
			s[stri+sd]='a' 
			sd+=1 
			
		if c==0: 
			s[stri+sd]='A' 
	print(''.join(s))