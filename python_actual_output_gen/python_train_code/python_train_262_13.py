n=int(input())
a=int(n**0.5)+1
if n%2==0:
	print(n//2)
else:
	for i in range(3,a+1,2):
		if n%i==0:
			print(n//i)
			exit()
	print("1")