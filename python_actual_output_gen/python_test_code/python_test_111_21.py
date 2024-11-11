N=int(input())
H=list(map(int,input().split()))
a=b=c=0

for i in range(N):
	if H[i]<=a:
		a=H[i]
		b+=1
		if b>=c:
			c=b
	else:
		a=H[i]
		b=0
print(b)