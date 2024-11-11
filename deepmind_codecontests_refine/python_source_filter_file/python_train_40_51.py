a,b=map(int,input().split())
num=a
while a//b>=1:
	a-=b
	a+=1
	num+=b
print(num+a)