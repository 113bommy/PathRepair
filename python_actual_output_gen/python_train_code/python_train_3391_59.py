n = input()
n = int(n)

g = input()
g = list(g)
g.sort()
if n%2 != 0:
	if g[n//2] == 'A':
		print('Anton')
	else:
		print('Derek')
else:
	if g[n//2-1]!=g[n//2]:
		print('Friendship')
	elif g[n//2] == 'A':
		print('Anton')
	else:
		print('Derek')