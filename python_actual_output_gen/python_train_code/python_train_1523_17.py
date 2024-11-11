def fun(elem):
	return elem[1]


n=int(input())
a = input().split()
b=[]
for i in range(n):
	b.append((i,a[i]))
b.sort(key=fun)
for i in b:
	print(i[0]+1,end=' ')