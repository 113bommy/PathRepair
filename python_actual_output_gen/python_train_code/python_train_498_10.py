#Rohan Bojja 
#rohan.bojja@gmail.com

#######################################
c=1
cases=1

while(c<=cases):
	[k,a,b]=[int(i) for i in input().split()]
	ans=-1
	if(a>=k and b>=k):
		ans=(a//k)+(b//k)
	if(a>=k):
		if(a%k==0):
			ans=a//k
	if(b>=k):
		if(b%k==0):
			ans=b//k
	print(ans)
	c=c+1
