n,m=map(int,input().split())
a=list(map(int,input().split()))
b=list(map(int,input().split()))
z,k=0,0
x=0
w=0
for i in range(m):
	if b[i]%2==0:
		z+=1
	else:
		x+=1	
for i in range(n):
	if a[i]%2==0:
		k+=1
	else:
		w+=1							
print(min(z,w)+min(k,x))		