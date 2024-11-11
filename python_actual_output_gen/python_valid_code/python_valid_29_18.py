n,m,k = [int(x) for x in input().split(' ')]

biloMest = 0
for row in range(1,n+1):
	if k > biloMest and k < 2*m+biloMest:
		bilo = 1+biloMest
		for parta in range(1,m+1):
			if k == bilo or k == bilo+1:
				if k%2==0:
					print(str(row)+' '+str(parta)+' R')
				else:
					print(str(row)+' '+str(parta)+' L')
			bilo+=2
		break
	biloMest += m*2