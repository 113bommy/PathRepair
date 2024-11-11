
n, k = input().split()
n = int(n)
k = int(k)

part = [int(i) for i in input().split()] # insert a list of consecutive integers

if part[0] == 0:
	print(0)
elif part[0] == part[n-1]:
	print(n)
elif k!=n and part[k-1]!=0 and part[k-1] == part[k]:
	print(k + part[k:n].count(part[k]))
else:
	if 0 in part[0:k]:
		j = part.index(0)
		print(j)
	else:
		print(k)