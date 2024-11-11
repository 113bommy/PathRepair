import math       
n=int(input())
arr=list(map(int,input().split()))
if(n==1):
	gcd=arr[0]
else:
	num1 = arr[0]
	num2 = arr[1] 
	gcd = math.gcd(num1, num2) 
	for i in range(2, n): 
	    gcd = math.gcd(gcd, arr[i]) 
i = 1
res=0
while i <= math.sqrt(n): 
	if (gcd % i == 0) : 
		if (gcd / i == i) : 
			res+=1 
		else : 
			res+=2
	i=i+1
print(res)