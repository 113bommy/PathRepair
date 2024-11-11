x=input()
a,b,c=map(int,x.split())


def case1(s):
	if(s<0):
		print('-')
	elif(s==0):
		print('0')
	elif(s>0):
		print('+')

if(c==0):
	case1(a-b)
else:
	x=a-b
	if(x<0):
		x=x*-1
	if(c<x):
		case1(a-b)
	else:
		print('?')

