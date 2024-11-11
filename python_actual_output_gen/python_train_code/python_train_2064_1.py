I=input
I()
s=I()+'()'
R=str.replace
t=a=b=0
for i in filter(lambda x:x,R(R(s,'(',')'),')','_').split('_')):
	t=s.find(i,t)
	if s.find('(',t)<s.find(')',t):a=max(a,len(i))
	else:b+=1
print(a,b)