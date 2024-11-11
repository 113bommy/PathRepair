# -*- coding: utf-8 -*-
#ARC082C
import copy
import sys
import math

n = int(input())
tmp = input().split()
hoge = list(map(lambda a: int(a), tmp))

hoge.sort()
hoge.append(-1)
a=0
b=0
c=1
maxhoge=0
for i in range(0,n):
	if(hoge[i]!=hoge[i+1]):
		if(i!=n-1):
			if(hoge[i+1]-hoge[i]==1):
				a=b
				b=c
				c=1
			elif(hoge[i+1]-hoge[i]==2):
				a=c
				b=0
				c=1
			else:
				a,b=0
				c=1
	else:
		c+=1
#	print("i:{} | {} {} {}".format(i,a,b,c))

	maxhoge=max(maxhoge,a+b+c)



#print(hoge)
print(maxhoge)

