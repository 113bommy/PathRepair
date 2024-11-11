x,y,a,b = input().split()
x = int(x)
y = int(y)
a = int(a)
b = int(b)
l = []
for i in range(b,y+1):
	for j in range(i+1,x+1):
		l.append((j,i))
print(len(l))
l.sort(key = lambda x:x[0])
for i in range(len(l)):
	print(l[i][0],l[i][1])
