n=list(input())
x=n.count("-")
z=n.count("o")
if z!=0 and x%z==0:
	print("YES")
elif z==0:
	print("NO")
else:
	print("NO")