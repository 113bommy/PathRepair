for i in range(int(input())):
	n =int(input())
	fact=1
	for i in range(3,n+1):
		fact*=i
		fact%=1000000007
	print(fact)