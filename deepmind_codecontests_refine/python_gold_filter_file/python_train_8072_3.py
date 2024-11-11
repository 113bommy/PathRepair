n=int(input())
l=list(map(int,input().split()))
a=0
b=0
v1=0
v2=n-1
while v2>=v1:
	if a>b:
		b+=l[v2]
		v2-=1
	else:
		a+=l[v1]
		v1+=1
print(v1,n-v1)
