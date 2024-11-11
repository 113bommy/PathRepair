
n=int(input())
rat=[]
man=[]
wc=[]
cap=[]
for i in range(n):
	name,title=map(str,input().split())
	if title=='captain':
		cap.append(name)
	elif title=='man':
		man.append(name)
	elif title=='rat':
		rat.append(name)
	else:wc.append(name)
rat.sort()
man.sort()
wc.sort()
cap.sort()
for i in range(len(rat)):
	print(rat[i])
for i in range(len(wc)):
	print(wc[i])
for i in range(len(man)):
	print(man[i])
for i in range(len(cap)):
	print(cap[i])