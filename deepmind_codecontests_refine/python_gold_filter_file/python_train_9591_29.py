x,y = map(int,input().split())
l = list(map(int,input().split()))
t1 = l.count(1)
t2 = l.count(-1)
max1 = 0
for i in range(y):
	r1 = t1
	r2 = t2
	for j in range(i,x,y):
		if l[j] == 1:
			r1 = r1 - 1
		if l[j] == -1:
			r2 = r2 - 1
	max1 = max(max1,r1-r2,r2-r1)
print(max1)