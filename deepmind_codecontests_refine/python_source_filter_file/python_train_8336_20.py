import math,sys
from sys import stdin, stdout
from collections import Counter, defaultdict, deque
input = stdin.readline
I = lambda:int(input())
li = lambda:list(map(int,input().split()))

def case():
	n=I()
	a=li()
	c=Counter(a)
	a=set(a)
	ans=[]
	answer=0
	for i in c:
		p=i 
		k=1
		flag=0
		while(k<=1000000000):
			if((k-i) in c and (k-i)!=i):
				flag=1 
				break
			elif((k-i)==i and c[i]>1):
				flag=1 
				break
			else:
				k*=2
		if(flag==0):
			answer+=c[i]
	print(answer)
	
	

for _ in range(1):
	case()