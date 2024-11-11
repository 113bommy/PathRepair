a=list(input())
b=list(input())
z=[]
l=0
eq=0
gr=0
for n in range(len(a)-1,-1,-1):
	if a[n]=='z':
		a[n]='a'
	else:
		a[n]=chr(ord(a[n])+1)
		break
if a!=b:
	print(''.join(a))
else:
	print('No such string')
		