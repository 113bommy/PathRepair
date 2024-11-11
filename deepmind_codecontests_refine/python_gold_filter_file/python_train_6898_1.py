t = int(input())
 
for asd in range(t):
	s = str(input())
	a=[]
	if(s[0]=='1'):
		count=1
	else:
		count=0
	for i in range(0,len(s)-1):
		if(s[i+1]=='1' and s[i]=='0'):
			count=1
		elif(s[i+1]=='1' and s[i]=='1'):
			count+=1
		elif(s[i+1]=='0' and s[i]=='1'):
			a.append(count)
			count=0
	a.append(count)
# 	print(a)
	a.sort()
	
	count =0 
	for i in range(len(a)-1,-1,-2):
		count+=a[i]
	print(count)