
n = int(input())
y = [-2*10**9,2*10**9]
k=[]
f=0
for i in range(n):
	k.append(list(map(str,input().split())))

for i in range(n):
	x = int(k[i][1])
	if k[i][2]=='N':
		if k[i][0]=='>':
			k[i][0]='<='
		elif k[i][0]=='>=':
			k[i][0]='<'
		elif k[i][0]=='<':
			k[i][0]='>='
		else:
			k[i][0]='>'
	if k[i][0]=='>':
		y[0]=max(x+1,y[0])
	elif k[i][0]=='<':
		y[1]=min(x+1,y[1])
	elif k[i][0]=='<=':
		y[1]=min(x,y[1])
	else:
		y[0]=max(x,y[0])
	if y[0]>y[1]:
		f=1
		break
if f :
	print("Impossible")
else:
	print(y[0])
