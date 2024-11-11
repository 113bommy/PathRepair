def solve(r,x2a,y2a):
	b=r/(1+abs(y2a/x2a)**2)**0.5
	h=r/(1+abs(x2a/y2a)**2)**0.5
	xa=(abs(x2a)-b)/2;ya=(abs(y2a)-h)/2
	#print(-b,-h,"b h")
	if x2a<0 and y2a<0:
		return [xa*-1,ya*-1]
	elif x2a<0 and y2a>0:
		return [xa*-1,ya]
	elif x2a>0 and y2a>0:
		return [xa,ya]
	else:
		return [xa,ya*-1]
def check(x1,x2,y1,y2,r):
	if((x1-x2)**2+(y1-y2)**2)**0.5>r:
		print(x1,y1,r);return True
	else:
		if x1==x2 and y1==y2:
			print((x1+(x1+r/2**0.5))/2,(y1+(y1+r/2**0.5))/2,r/2);return True
		elif x1==x2 and y1!=y2:
			if y1-y2<0:
				r1=abs((y1-r+y2)/2-(y1-r))
				print(float(x1),(y1-r+y2)/2,r1);return True
			else:
				r1=abs((y1+r+y2)/2-(y1+r))
				print(float(x1),(y1+r+y2)/2,r1);return True
		elif y1==y2 and x1!=x2:
			if x1-x2<0:
				r1=abs((x1-r+x2)/2-(x1-r))
				print((x1-r+x2)/2,float(y1),r1);return True
			else:
				r1=abs((x1+r+x2)/2-(x1+r))
				print((x1+r+x2)/2,float(y1),r1);return True
		else:
			return False


r,x1,y1,x2,y2=map(int,input().split(' '))
#x2-=x1;y2-=y1;x1-=x1;y1-=y1
if check(x1,x2,y1,y2,r)==False:
	t=solve(r,x2-x1,y2-y1);
	#print(t)
	xa=t[0]+x1;ya=t[1]+y1
	r1=((xa-x2)**2+(ya-y2)**2)**0.5
	print(xa,ya,r1)
