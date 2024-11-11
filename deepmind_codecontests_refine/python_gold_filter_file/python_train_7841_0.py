n=int(input())
#count=n


def pebbles(n,count):
	'''
	if n==1:
		count+=1
		return count
	'''
	#print(n)
	maxi=0
	a=2
	while a*a<=n:
		b=n/a
		#print(b)
		if b%1==0 and b>maxi:
			maxi=b
		a+=1
	count+=maxi
	#print(n)
	#print(maxi,count)
	if maxi==0:
		count+=1
		print(count)
		return
	pebbles(int(maxi),int(count))

if n==1:
	print(1)
else:
	pebbles(n,n)

