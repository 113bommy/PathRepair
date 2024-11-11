m=int(input())
s=list(map(int,input().split()))
y=[]
for i in range(m):
	x=s[i]
	if x%2==0:
		m=x-1
		y.append(m)
	elif x%2==1:
		y.append(x)
for i in range(len(y)):
	print(y[i] ,end=' ')