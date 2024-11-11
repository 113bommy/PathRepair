n=int(input())
a=2**n
if (n>31):
	a-=2**22*100
print(a)