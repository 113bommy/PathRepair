import math
from collections import defaultdict as dq

def primeFactors(n): 
	d=dq(int)
	while n % 2 == 0: 
		d[2]+=1
		n = n // 2

	for i in range(3,int(math.sqrt(n))+1,2): 
		while n % i== 0: 
			d[i]+=1
			n = n // i 
	if n>1:
		d[n]+=1
	return d

for _ in range(int(input())):
	n=int(input())
	s=primeFactors(n)
	if len(s)>2:
		c=0
		li=[]
		for i in s.keys():
			li.append(i)
			c+=1
			if c==2:
				break
		print("YES")
		print(li[0],li[1],n//(li[0]*li[1]))
	if len(s)==1:
		for i in s.keys():
			c=i
		if s[c]>=6:
			print("YES")
			print(c,c*c,c*c*c)
		else:
			print("NO")
	if len(s)==2:
		li=[]
		for i in s.keys():
			li.append(i)
		if 	n//(li[0]*li[1]) in s.keys() or n//(li[0]*li[1])==1 :
			print("NO")
		else:
			print("YES")
			print(li[0],li[1],n//(li[0]*li[1]))
