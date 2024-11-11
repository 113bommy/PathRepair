x=int(input())
y=list(map(int, input().split()))
t=1
for i in range(x):
	if y[i]<0:
		t=t*-1
	y[i]=abs(y[i])

if y==1:
	print(sum(y))
else:
	print(sum(y)-(min(y)*2))