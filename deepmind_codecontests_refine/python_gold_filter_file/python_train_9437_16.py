import math as ma
from sys import exit
def li():
	return list(map(int,input().split()))
def num():
	return map(int,input().split())
def nu():
	return int(input())
s=input()
f=[0]*26
for ch in s:
	f[ord(ch)-97]+=1
c=0
x=[]
v=[]
for i in range(26):
	if(f[i]>0):
		c+=1
		x.append(i)
		v.append(f[i])
xx=sorted(zip(v,x))
if(c==1):
	print("No")
	exit()
if(c%2==0):
	if((c==2 and(xx[0][0]!=1)) or c==4):
		print("Yes")
	else:
		print("No")
else:
	if(c==3):
		if(xx[0][0]==1 and xx[1][0]==1 and xx[2][0]==1):
			print("No")
		else:
			print("Yes")
	else:
		print("No")
