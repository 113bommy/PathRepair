from sys import *

def mask(a):
	res1=''
	while a>0:
		p=(a%10)%2
		res1+=str(p)
		a//=10
	res1+='0'*(18-len(res1))
	return res1[::-1]

di=dict()
t=int(stdin.readline())
for i in range(t):
	s=stdin.readline().split()
	if s[0]=='+':
		w=mask(int(s[1]))
		if di.get(w,-1)==-1:
			di[w]=1
		else:
			di[w]+=1
	if s[0]=='-':
		w=mask(int(s[1]))
		di[w]-=1
	if s[0]=='?':
		w=mask(int(s[1]))
		if di.get(w,-1)==-1:
			print('0')
		else:
			print(di[w])