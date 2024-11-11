n, m = map(int, input().split())
puzl = sorted(map(int, input().split()))


minDif = puzl[n-1] - puzl[0]
for i in range(1, m-n-1):
	if((puzl[i+n-1] - puzl[i]) < minDif):
		minDif = (puzl[i+n-1] - puzl[i])

print(minDif)