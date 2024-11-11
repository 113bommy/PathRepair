n = int(input())

a = "i hate that "
b = "i love that "

if n%2 == 0:
	print(int((n/2)-1)*(a+b) + "i hate that i love it")
if n%2 != 0:
	print(int(n/2)*(a+b) + "i hate it")