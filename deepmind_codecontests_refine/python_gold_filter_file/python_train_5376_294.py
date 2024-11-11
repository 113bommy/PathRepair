n=int(input())
m=int(input())

if n>100:
	print(m)
	exit()
print(m%(2**n))