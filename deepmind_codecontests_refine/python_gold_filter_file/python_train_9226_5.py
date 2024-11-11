n=int(input())
for r in range(n):
	chic=int(input())
	while chic>0:
		if chic%3==0:
			chic=7
		chic-=7
	if(chic==0):
		print('YES')
	else:
		print('NO')
