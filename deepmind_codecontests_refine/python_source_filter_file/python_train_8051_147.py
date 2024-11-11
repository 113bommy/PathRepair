n=int(input())
a=list(map(int,input().split()))
x=0
for i in range(n):	
	x=(a[i]/100)
	x=x+1
print(float(x/n)*100)
