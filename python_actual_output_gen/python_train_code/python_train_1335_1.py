n = int(input())

for i in range(n):
	r,g,b = map(int,input().split())
	l = [r,g,b]
	l.sort()
	if l[2] >= l[0]+l[1]:
		print(l[0]+l[1])
	elif (l[2]-l[1]-l[0])%2 == 0:
		print(l[2]+(-l[2]+l[0]+l[1])//2)
	elif (l[2]-l[1]-l[0])%2 == 1:
		print(l[2]-1+(-l[2]+l[0]+l[1])//2)