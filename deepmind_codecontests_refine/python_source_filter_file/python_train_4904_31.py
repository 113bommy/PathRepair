n = int(input())
if n == 1 and n == 2:
	print("No")
else:
	print("Yes")
	if n%2 == 0:
		print(n//2,end = " ")
		for i in range(1,n//2+1):
			print(2*i,end = " ")
		print()
		print(n//2,end = " ")
		for i in range(1,n//2+1):
			print(2*i-1,end = " ")
	else:
		print(n//2,end = " ")
		for i in range(1,n//2+1):
			print(2*i,end = " ")
		print()
		print(n//2+1,end = " ")
		for i in range(1,n//2+2):
			print(2*i-1,end = " ")



