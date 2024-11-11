a,b = input().split()
x = int(a)
k = int(b)
mod = 10**9 + 7
if(x == 0 ):
	print(0)
elif( k == 0):
	print(2*x)
else:
	print( (((pow(2,k,mod)*x - pow(2,k-1,mod))%mod)*2 + 3*mod + 1)%mod)