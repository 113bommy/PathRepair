from array import *

a,  b = map(int,input().split())
aa= input().split()
av = array('i',[])
sum = 0
for i in range(a):
	av.append(int(aa[i]))
	if av[i] >= b:
		sum = sum + 2
	else:
		sum = sum + 1
print(sum)