d={}
d['A']='A'
d['X']='X'
d['W']='W'
d['Y']='Y'
d['O']='O'
d['I']='I'
d['M']='M'
d['T'],d['U'],d['V'],d['H']='T','U','V','H'
d['o'],d['v'],d['w'],d['x'],d['q'],d['p'],d['d'],d['b']='o','v','w','x','p','q','b','d'

s=input()
if len(s)==1:
	x=s[0]
	y=['A','O','X','W','V','U','I','T','o','x','v','w','m']
	if x in y:
		print('TAK')
	else:
		print('NIE')
	exit(0)
j=len(s)//2
k=len(s)-1
i,flag=0,True

while i<=j:
	try:
		x=d[s[i]]
		y=s[k]
		if x!=y:
			flag=False
			break
		i+=1
		k-=1
	except:
		print('NIE')
		exit(0)
if flag:
	print('TAK')
else:
	print('NIE')