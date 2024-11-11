import itertools
while True:
	try: n=int(input())
	except EOEError: break
	ans=0
	for (i,j,k) in itertools.product(range(10),range(10),range(10)):
		ans+=(0<=n-(i+j+k)<=9)
	print(ans)

