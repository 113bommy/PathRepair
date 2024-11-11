s=str(input())
if(s[0]=="*"):
	print("0")
else:
	x=-1
	for i in range(0,len(s)):
		if(s[i]=='.'):
			x=i
			break
	#print(x)


	if(x==-1):
		if(s[0]!='-'):
			t='$'
			for i in range (0,len(s)):
				t+=s[i]
				if((len(s)-i-1)%3==0 and i!=len(s)-1):
					t+=","
			t+=".00"
		else:
			t='($'
			for i in range (1,len(s)):
				t+=s[i]
				if((len(s)-i-1)%3==0 and i!=len(s)-1):
					t+=","
			t+=".00)"
		print(t)
	else:
		u=""
		if(s[0]!='-'):
			t='$'
			for i in range (0,x):
				t+=s[i]
				if((x-i-1)%3==0 and i!=x-1):
					t+=","
			for j in range(x,len(s)):
				u+=s[j]
			
			if(len(u)==2):
				t=t+u+"0"
			elif(len(u)==3):
				t=t+u
			else:
				t=t+u[:3]

			
		else:
			t='($'
			for i in range (1,x):
				t+=s[i]
				if((x-i-1)%3==0 and i!=x-1):
					t+=","
			for j in range(x,len(s)):
				u+=s[j]

			if(len(u)==2):
				t=t+u+"0)"
			elif(len(u)==3):
				t=t+u+")"
			else:
				t=t+u[:3]+")"
		print(t)

	



