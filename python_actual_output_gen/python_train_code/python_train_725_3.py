T=int(input())
ang=[int(input()) for _ in range(T)]
for a in ang:
	for n in range(3,181):
		if(a%(180/n)==0):
			x=a//(180/n)
			if((n-2)>=x):
				print(n)
				break
	else:
		print(-1)
