n = int(input())
l1 = []
for i in range(n):
	l = list(map(int,input().split()))
	l1.append(l)
c = 0
for i in range(len(l1)):
	l2 = l1[i]
	if(l2[1]-l2[0]>2):
		c = c+1
print(c)