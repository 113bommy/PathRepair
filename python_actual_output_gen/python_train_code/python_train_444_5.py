s=[int(n) for n in input().split()]
z=[int(n)%2 for n in input().split()]
if s[1]%2==0:
	if z[len(z)-1]%2==0:
		print('even')
	else:
		print('odd')
else:
	if sum(z)%2==0:
		print('even')
	else:
		print('odd')