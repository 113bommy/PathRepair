from collections import *
import sys  

# "". join(strings)  
    
def ri():
    return int(input())
 
def rl():
    return list(map(int, input().split()))


def computeGCD(x, y): 
  
   while(y): 
       x, y = y, x % y 
  
   return x 

t=ri()

for _ in range(t):

	n= ri()
	aa=rl()
	bb=[]
	for i, ai in enumerate(aa):
		bb.append([ai, i])
	bb.sort()
	mini = bb[0][0]
	ans=1
	for i in range(n):
		b = bb[i][0]
		a = aa[i]
		if a==b:
			continue
		if a%mini!=0:
			ans=0
			break
		if b%mini!=0:
			ans=0
			break
		if computeGCD(a, b)!=mini:
			ans=0
			break
	if ans==1:
		print("YES")
	else:
		print("NO")


