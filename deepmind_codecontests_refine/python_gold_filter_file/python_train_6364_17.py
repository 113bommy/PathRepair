from sys import stdin,stdout
from collections import defaultdict
import math
#stdin = open('input.txt', 'r')  
I = stdin.readline
P = stdout.write
	

n = int(I())
arr = [int(x) for x in I().split()]
t = 1
ans = math.inf
for i in range(1,max(arr)+1):
	now = 0
	for j in arr:
		if(j<i):
			now+=(i-1-j)
		elif(j>i):
			now+=(j-i-1)
	if(now<ans):
		ans = now
		t = i
print(t,ans)



	

			







      
   






















        
       
    




