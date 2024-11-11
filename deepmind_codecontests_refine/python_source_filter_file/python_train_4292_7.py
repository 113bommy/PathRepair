import math 
from collections import defaultdict
def primeFactors(n): 
	d=defaultdict(int)

	while n % 2 == 0: 
		d[2]+=1
		n = n // 2

	for i in range(3,int(math.sqrt(n))+1,2): 
		
		while n % i== 0: 
			d[i]+=1
			n = n / i 
			
	if n > 2: 
		d[n]+=1 
	
	return d

t=int(input())
for i in range(t):
	n=int(input())
	d= primeFactors(n)
	# print(d)
	if len( d.keys() )>=3:
		print("YES")
		s=[]
		ww=1
		for j in list(d.keys())[:2]:
			s.append( int(j**d[j]) )
			ww*=j**(d[j]-1)
		
		for j in list(d.keys())[2:]:
			ww*= int(j**d[j])
		
		s.append(ww)
		print(*s)
	elif len(list(d.keys()))==1:
		w,w1 = int(list(d.keys())[0]), int(d[list(d.keys())[0]]) 

		if w1>=6:
			print("YES")
			ans = "{} {} {}".format(w,w**2,w**(w1-3))
			print(ans)
		else:
			print("NO")
	elif len(list(d.keys()))==2:
		keys= list(map(int,list(d.keys())))
		value = list(map(int,list(d.values())))
		if sum(value)>=4:
			print("YES")
			ans = "{} {} {}".format( keys[0], keys[1], keys[0]**(value[0]-1) * keys[1]**(value[1]-1) )
			print(ans)
		else:
			print("NO")
