l , r=map(int,input().split())
i = 1
even = 0
a = 0 
b = 0
c = 0
d = 0
sums = 0
ol = 0
ori = 0
el = 0
er = 0
while(i  <= r):
	if(even):
		
		b+=i
		if(i*2 < l ):
			d = b
		if(i * 2 > l  and i  < l ):
		
			el = l - i + d 
			ol = a 
		if(i * 2 > r  and i  < r ):
		
			er =  b - (i * 2 - r) + 1
			ori = a
	else:
	
		a+=i
		if(i*2 < l ):
			c = a

		if(i * 2 > l  and i  < l ):
	
			ol = l - i + c 
			el  = b 

		if(i * 2 > r  and i  < r ):
	
			er= b
			ori =  a - (i * 2 - r) + 1
		
	i = i * 2


	even^=1

g = ((ori * ori)) - ((ol*ol))
k = ((er)*(er+1)) - (el*(el+1))

sums = ((ori * ori)) - ((ol*ol)) + ((er)*(er+1)) - (el*(el+1))
sums = sums % 1000000007


print(sums)