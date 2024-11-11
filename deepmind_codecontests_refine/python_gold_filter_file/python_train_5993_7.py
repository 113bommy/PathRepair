I=input
I()
s=I()+'()'
R=str.replace
a=b=0
t=-1
for i in filter(lambda x:x,R(R(s,'(',')'),')','_').split('_')):
	t=s.find(i,t+1)
	if s.find('(',t)<s.find(')',t):a=max(a,len(i))
	else:b+=1
print(a,b)