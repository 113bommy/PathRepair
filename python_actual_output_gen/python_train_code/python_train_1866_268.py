n=int(input())
m=int(input())
if m>1000:
	print(m)
	exit()
print(m%(2**n))