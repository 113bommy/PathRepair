import sys
n=int(input())
jsum=0
gjlist=[]
ejlist=[]
esum=0

def jouka(t):
	global jsum
	global gjlist
	global ejlist
	global esum
	
	tmpj=0
	tmpe=0
	
	for i in range(len(t)):
		if t[i] == "(":
			tmpj += 1
		else:
			if tmpj == 0:
				tmpe +=1
			else:
				tmpj -=1
		
	if tmpe == 0:
		jsum += tmpj
	elif tmpj == 0:
		esum += tmpe
	elif tmpj > tmpe:
		gjlist.append([tmpe,tmpj])
	else:
		ejlist.append([tmpe,tmpj])

for j in range(n):
	jouka(input())

gjlist.sort(key=lambda x:x[0])
ejlist.sort(reverse = True,key=lambda x:x[0])

streak=jsum
for gj in gjlist:
	if gj[0] > streak:
		print("No")
		sys.exit()
	else:
		streak += gj[1]-gj[0]

for ej in ejlist:
	if ej[0] > streak:
		print("No")
		sys.exit()
	else:
		streak += gj[1]-gj[0]

if streak == esum:
	print("Yes")
else:
	print("No")



