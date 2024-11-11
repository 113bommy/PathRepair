from math import log

x=[int(n) for n in input().split()]
l=0
for n in range(len(x)):
	print(x.count(x[n]))
	x[n]=log(x[n])
	if x.count(x[n])==1:
		l+=1
				
print(4-l)