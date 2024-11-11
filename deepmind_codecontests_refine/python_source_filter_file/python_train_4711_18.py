x=int(input())
for i in range(x):
	n=int(input())
	l=[int(x) for x in input().split()]
	l.sort()
	print(min(l[j]-l[j+1] for j in range(n-1)))