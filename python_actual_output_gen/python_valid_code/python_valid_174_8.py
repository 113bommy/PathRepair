# your code goes here
# your code goes here
n,k=[int(x) for x in input().split()]
#print(n,' ',k)
var=[int(x) for x in input().split()]
#print(var)
i=0
var=sorted(var)
while(i!=n and k!=0):
	if(var[i]<0):
		var[i]=-1*var[i]
		k-=1
	i+=1
	
mini=var.index(min(var))
if(k%2==1):
	#print("I am here")
	#print(var[mini])
	var[mini]=-1*var[mini]
#	print(var[mini])
sum1=0
for index in var:
	print(index)
	sum1+=index
print(sum1)




	

