n,k=map(int,input().split())
s=input()
a=[]
a.append(0)
for i in range(len(s)-1):
	if s[i] != s[i+1]:
		a.append(i+1)
a.append(n)
if s[-1]=='0':
	m=2*k
else:
	m=2*k+1
t=4*k+1
_max=0
i=len(a)-1
if i- m<0:
	print(n)
else:
	while i-m>=0:
		tmp=a[i]-a[i-m]
		print('i:{} tmp:{}'.format(i,tmp))
		if tmp>_max:
			_max=tmp
		m=t-m
		i-=1
	if a[i]>_max:
		_max=a[i]
	print(_max)