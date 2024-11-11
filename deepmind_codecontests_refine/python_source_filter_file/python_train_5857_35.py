t = int(input())

for i in range(t):
	n,r = map(int,input().split())

	w = min(n,r)

	if r>n:
		print( ((w-1)*w)//2 +1 )
	else:
		print( ((w+1)*w)//2 )