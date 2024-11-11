a,b,c=map(int,input().split())
p=a*b
while(a!=0 and b!=0):
	a,b=b,a%b
k=p//a
print(c//k)