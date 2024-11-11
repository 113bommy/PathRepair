n=int(input())
p=list(map(int,input().split()))
x=0
for i in range(n):
	a=p[i]/100
	x=x+a
print((float(x/n))*100)
