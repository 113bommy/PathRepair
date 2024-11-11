n=int(input())
z=0
a=[]
if n%2==0:
	for i in range(n):
		if i%2==0:
			z+=n//2
			t="c."*(n//2)
			a.append(t)
		else:
			t=".c"*(n//2)
			a.append(t)
			z+=n//2
else:
	for i in range(n):
		if i%2==0:
			z+=n//2+1
			t="c."*(n//2)+"c"
			a.append(t)
		else:	
			z+=n//2
			t=".c"*(n//2)+"."
			a.append(t)
print(z)
for i in range(len(a)):
	print(a[i])			