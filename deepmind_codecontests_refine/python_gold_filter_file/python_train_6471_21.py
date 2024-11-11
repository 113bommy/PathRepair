n=int(input())-1
i=0
while n>=(9*(i+1)*(10**i)):
	n-=(9*(i+1)*(10**i))
	i+=1
	# print (n)
a=int(pow(10,i))+int(n/(i+1))
# print (a)
print(str(a)[n%(i+1)])