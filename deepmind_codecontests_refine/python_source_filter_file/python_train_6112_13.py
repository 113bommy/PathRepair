a,b = map(int,input().split())
x = list(map(int,input().split()))
y = list(map(int,input().split()))
for i in range(len(x)):
	for j in range(len(y)):
		if x[i] == y[j]:
			print(y[j],end="")