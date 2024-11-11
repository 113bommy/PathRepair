n=int(input())
n-=10
if n<=0 or n>11:
	print(0)
elif (n>0 and n<10) or n==11:
	print(4) 
else: 
	print(15)