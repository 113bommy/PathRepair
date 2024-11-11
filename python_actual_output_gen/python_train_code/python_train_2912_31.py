n = int(input())

for i in range(n+1,9001):
	l=list(map(int,str(i)))
	if len(set(l)) == len(l):
		print(i)
		break