import copy
n=int(input())
l=list(map(int,str(n)))
a=l.count(0)
s=""
if a>0:
	print("YES")
	print("0")
elif n%8==0:
	print("YES")
	print(n)
elif l.count(8)>0:
	print("YES")
	print("8")
elif l.count(1)>0 and l.count(6)>0 and l.index(1)<l.index(6):
	print("YES")
	print("16")
elif l.count(2)>0 and l.count(4)>0 and l.index(2)<l.index(4):
	print("YES")
	print("24")
elif l.count(3)>0 and l.count(2)>0 and l.index(3)<l.index(2):
	print("YES")
	print("36")
elif l.count(5)>0 and l.count(6)>0 and l.index(5)<l.index(6):
	print("YES")
	print("56")
elif l.count(6)>0 and l.count(4)>0 and l.index(6)<l.index(4):
	print("YES")
	print("64")
elif l.count(7)>0 and l.count(2)>0 and l.index(7)<l.index(2):
	print("YES")
	print("72")
elif l.count(9)>0 and l.count(6)>0 and l.index(9)<l.index(6):
	print("YES")
	print("96")
else:
	k=len(l)
	mn=0
	for i in range(0,k):
		for j in range(i+1,k):
			for t in range(j+1,k):
				s=""
				s=s+str(l[i])
				s=s+str(l[j])
				s=s+str(l[t])
				s=int(s)
				if(s%8==0):
					mn=1
					print("YES")
					print(s)
					s=""
					break
			if mn==1:
				break
		if mn==1:
			break
	if mn==0:
		print("NO")
