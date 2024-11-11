for _ in range(int(input())):
	n=int(input())
	p=list(map(int,input().split()))
	n_max= n//2
	max_g= n//6
	g,s,b=0,0,0
	L=[]

	if n>10:
		
		if p[n_max-1]==p[n_max]:
			i=n_max-1
			while p[i]==p[i+1] and i>0:
				i=i-1
			n_max=i-1	
		
		if n_max>4:
			
			count=1
			for i in range(n_max):
				if p[i]==p[i+1]:
					count+=1
				else:
					L.append(count)
					count=1
			k=0
			g=g+L[k]
			k+=1
			if g<max_g:
				while k<len(L) and s<=g:
					s=s+L[k]
					k+=1

				while k<len(L):
					b+=L[k]
					k+=1
			if s<=g or b<=g or g==0 or s==0 or b==0 :
				g,s,b=0,0,0
	print(g,s,b)







					

				




