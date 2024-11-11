import math
from collections import OrderedDict		



t = int(input())
while(t>0):
	k = int(input())
	sr = math.sqrt(k)
	if(sr%1==0):
		print(int(sr) , 1)
	else:
		low = int(sr)
		high = low + 1
		r = high
		c = high	
		low = low**2 + 1
		high = high**2
		mid = (low + high)//2
		# print(low , mid , high)
		if(k == mid):
			print(r,r)
		if(k>= low and k<mid):
			print(r-(mid-k),c)
		else:
			print(r , c - (k-mid))		
	t-=1	




#							▀█ ▄█ █▀█ █▀█ 
#							█▄ ░█ █▄█ █▄█



















