from sys import stdin,stdout,exit
import math
from fractions import gcd
def sin(): 
	return stdin.readline().rstrip()
def listInput():
	return list(map(int,sin().split()))
def printBS(li):
	if not li: return
	for i in range(len(li)-1):
		stdout.write("%d "%(li[i]))
	stdout.write("%d\n"%(li[-1]))
dic={(0,0,0):"ABC",(0,0,1):"Impossible",(0,1,0):"ACB",(0,1,1):"CAB",(1,0,0):"BAC",(1,0,1):"BCA",(1,1,0):"Impossible",(1,1,1):"CBA"}
t=[0,0,0]
for i in range(3):
	s=sin()
	if "A" in s and "B" in s:
		if s[0]=="A":
			if s[1]=="<": t[0]=0
			else: t[0]=1
		else:
			if s[1]=="<": t[0]=1
			else: t[0]=0
	elif "C" in s and "B" in s:
		if s[0]=="C":
			if s[1]=="<": t[1]=1
			else: t[1]=0
		else:
			if s[1]=="<": t[2]=0
			else: t[1]=1
	else :
		if s[0]=="A":
			if s[1]=="<": t[2]=0
			else: t[2]=1
		else:
			if s[1]=="<": t[2]=1
			else: t[2]=0
print(dic[tuple(t)])