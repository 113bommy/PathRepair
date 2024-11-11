def func(x1,x2,x3,day):
	ba=0
	day=1
	while(1):
		if(day==8):
			day=1
		if(day==1 or day==4 or day==7):
			if(x1>0):
				ba+=1
				x1-=1
			else:
				break
		elif(day==2 or day==6):
			if(x2>0):
				x2-=1
				ba+=1
			else:
				break
		elif(day==3 or day==5):
			if(x3>0):
				x3-=1
				ba+=1
			else:
				break
		day+=1
	return ba

def tillmon(x1,x2,x3,da):
	ba=0
	while(1):
		if(da==8):
			da=1
		if(da==1):
			break
		if(da==1 or da==4 or da==7):
			if(x1>0):
				ba+=1
				x1-=1
			else:
				break
		elif(da==2 or da==6):
			if(x2>0):
				x2-=1
				ba+=1
			else:
				break
		elif(da==3 or da==5):
			if(x3>0):
				x3-=1
				ba+=1
			else:
				break
		da+=1
	return x1,x2,x3,ba
a2,b2,c2=map(int,input().split())
fina=[]

if(a2>5 and b2>5 and c2>5):
	for i in range(1,8):
		ans=0
		a,b,c,dd=tillmon(a2,b2,c2,i)
		ans+=dd
		t1=a//3
		t2=b//2
		t3=c//2
		a=a%3
		b=b%2
		c=c%2
		mini=min(t1,t2,t3)
		ans+=(mini-1)*7
		#print(mini,t1,t2,t3)
		a+=(t1-mini+1)*3
		b+=(t2-mini+1)*2
		c+=(t3-mini+1)*2
		ans+=func(a,b,c,1)
		fina.append(ans)
else:
	for i in range(1,8):
		ans=0
		ans+=func(a2,b2,c2,i)
		fina.append(ans)
print(max(fina))