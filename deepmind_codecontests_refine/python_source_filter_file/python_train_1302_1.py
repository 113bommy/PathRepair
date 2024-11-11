import math

p,k = map(int, input().split())
a = [0] * p
sets = 0
for i in range(p):
	if ( a[i] == 0 ):
		sets += 1
		r = i
		while ( a[r] == 0 ):
			a[r] = 1
			r = int(math.fmod(r * k,p)) 

if (k == 0):
	sets = 1
elif(k == 1):
	sets = p+1	
res = 1
big = 1000000007
for i in range(sets-1):
	res =  int(math.fmod(res * p,big))
print(int(res))

