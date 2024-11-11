for i in range(int(input())):
	n=int(input())
	l=sorted(list(map(int,input().split())),reverse=True)
	a=l[i]+1

	for i in range(n):
		a-=1
		for j in range(a):
			if(l[j]<a):
				break
		else:
			print(a)
			break