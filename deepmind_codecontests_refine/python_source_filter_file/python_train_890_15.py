a,b,c=map(int,input().split())
p=a
while(a!=0 and b!=0):
	a,b=b,a%b
k=p*b//a
print(c//p)