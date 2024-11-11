t=int(input())
while t>0:
	k=int(input())
	s=input()
	kt=True
	mp={}
	for i in range(len(s)):
		if int(s[i])==1:
			print(1)
			print(1)
			kt=False
			break
		if int(s[i]) %2==0 and s[i]!="2":
			print(1)
			print(s[i])
			kt=False	
			break
		if 	int(s[i])%3==0 and s[i]!='3':
			print(1)
			print(s[i])
			kt=False
			break	

	if kt==True:
		for i in range(len(s)):		
			if  s[i]=='2' and i!=0:
				print(i+1)
				print(s[i-1:i+1])
				kt=False
				break
			if  s[i]=='5' and i!=0:
				print(2)
				print(s[i-1:i+1])
				kt=False
				break
			if s[i] not in mp:
				mp[s[i]]=1
			else:
				print(2)
				print(s[i]+s[i])
				kt=False
				break
	if kt==True:			
		if "1" in s:
			if "2" in s:
				print(2)
				print(21)
			elif "5" in s:
				print(2)
				print(51)
		elif "7" in s:
			if "2" in s:
				print(2)
				print(27)
			elif "5" in s:
				print(2)
				print(57)
					

	

	t-=1	