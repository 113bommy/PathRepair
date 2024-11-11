n=int(input())
p=list(map(int,input().split()))
a=0
b=10**10
for i in range(n):
	if p[i] <= b:
		a+=1
		b=a
	else:
		pass
print(a+1)