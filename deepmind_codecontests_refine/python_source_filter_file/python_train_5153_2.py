from sys import stdin,stdout
from collections import defaultdict
import math
#stdin = open('input.txt','r')
I = stdin.readline
P = stdout.write

n,k = map(int,I().split())
r = defaultdict(lambda : 0 )
l = defaultdict(lambda : 0 )
arr = []
ans = 0
zero = 0
for i in I().split():
	i = int(i)
	if(i!=0):
		arr.append(i)
		r[i]+=1
	if(i==0):zero+=1
ans+=(zero*(zero-1)*(zero-2))//6
if(k!=1):
	
	for i in arr:
		k1,k2 = 0,0
		if(i%k == 0):
			#print(l,r,ans)
			k1 = l[i//k]
			k2 = r[i*k]
			ans+=k1*k2
		r[i]-=1
		l[i]+=1


	print(ans)
if(k == 1):
	ans = 0
	#print(r)
	for j in r:
		i = r[j]
		ans+=(i*(i-1)*(i-2))//6
	print(ans)











	

			







      
   






















        
       
    




