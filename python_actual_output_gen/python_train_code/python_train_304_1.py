n,k=map(int,input().split())
a=0
b=[str(i) for i in range(k+1)]
for i in range(n):
	nn=input()
	for j in b:
		if j not in nn:
			a+=1
			break
print(a)
