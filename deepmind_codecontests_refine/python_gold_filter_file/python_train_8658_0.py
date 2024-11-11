n,l,r=list(map(int,input().split()))
minsum=0
maxsum=0
t=0
if l==1:
	minsum=n
else:
	t=n-l+1
	minsum=t
	#l=l-1
	for i in range(1,l):
		#print(i)
		minsum=pow(2,i)+minsum



if r==1:
	maxsum=n
else:
	maxsum=pow(2,r-1)*(n-r+1)
	for i in range(0,r-1):
		maxsum=maxsum+pow(2,i)

print(minsum,end=' ')
print(maxsum)


