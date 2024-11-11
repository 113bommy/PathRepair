t=int(input())
for T in range(t):
	n=int(input())
	lista=[int(x) for x in input().split()]
	ma=max(lista)
	mi=min(lista)
	listb=[0]*n
	ans=0
	for k in range(1,ma*2+1):
		temp=0
		for i in range(n):
			listb[i]=lista[i]^k
		lista.sort()
		listb.sort()
		if(lista==listb):
			ans=1
			print(k)
			break
	if(ans==0):
		print(-1)




		

