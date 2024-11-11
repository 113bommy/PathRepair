import re;i=input;t=int(i())
while t:
	t-=1;p={};n=int(i())
	while n:
		n-=1;s=i();a=s.split()[::2]
		if':'in s:k,v=a;p[k]=(v[:3],v[-3:],v.count('haha'))
		else:k,x,y=a;a,b,c=p[x];d,e,f=p[y];p[k]=(a+d)[:3],(b+e)[-3:],c+f+len(re.findall('(?=haha)',b+d))
	print(p[k][2])