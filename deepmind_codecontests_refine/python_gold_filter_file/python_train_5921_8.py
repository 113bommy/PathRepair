w = int(input())
n = int(input())
l = list(range(1,w+1))
for i in range(n):
	a,b = map(int,input().split(','))
	a -= 1
	b -= 1
	l[a],l[b] = l[b],l[a]
for x in l:
	print(x)


