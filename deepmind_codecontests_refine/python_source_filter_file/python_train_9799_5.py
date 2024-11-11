s = list(input())
if len(s) < 3:
	print(*s,sep="")
else:
	if len(s) % 2 == 0:
		mid = len(s)//2
	else:
		mid = (len(s)//2)+1
	l1=[]
	l1.append(s[mid-1])
	l2 = s[:mid-1]
	l3 = s[mid:]
	a = 0
	for i in range(1,(len(s))//2):
		l1.append(l3[i-1])
		l1.append(l2[-i])
		a+=1
	if a!= len(l3):
		l1.append(l3[-1])
	if a != len(l2):
		l1.append(l2[-1])
	print(*l1,sep="")
