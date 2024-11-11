n=int(input())
x=[]
m=[]
mi=float("inf")
for i in range(n):
	a=list(map(int,input().split()))
	x.append(sorted(a[1:]))
	m.append(len(a[1:]))
# print(m)
# print(min(m))
mi=m.index(min(m))
# print(mi)
y=x.index(x[mi])
# print(x[y])
s=[]
for j in range(len(x[y])):
	# print(x[y][j])
	flag=0
	for i in range(n):
		if x[y][j] not in x[i]:
			flag=1
	if flag==0:
		s.append(x[y][j])
print(*s)