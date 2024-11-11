import random
import math
import sys
LI = lambda: list(map(int,input().split()))
MI = lambda: map(int,input().split())
yes = lambda: print("Yes")
no = lambda: print("No")
I = lambda: list(input())
J = lambda x: "".join(x)
II = lambda: int(input())
SI = lambda: input()
#---khan17---template
t = II()
l = [0,8]
for i in range(5,5*10**5,2):
	l.append(l[-1]+(i//2)*(i*4-4))
for q in range(t):
	n = II()
	print(l[n//2])
