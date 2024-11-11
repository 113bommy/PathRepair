n=int(input())
l=[]
for i in range(n+1):
	l.append(list(range(i+1))+list(range(i-1,-1,-1)))
for i in range(n+1):
	print(' '*(2*(n-i)),end='')
	print(*l[i],end=' ')
	print()
for i in range(n-1,-1,-1):
	print(' '*(2*(n-i)),end='')
	print(*l[i],end=' ')
	print('')