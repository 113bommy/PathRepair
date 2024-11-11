n=int(input())
l=list(map(int,input().split()))
l.sort()
for x in range(n-2):
	if l[x]+l[x+1]>=l[x+2]:
		print('YES')
		break
else:
	print('NO')