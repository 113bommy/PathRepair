n=int(input())
k=1
t=2
for i in range(0,n):
	print((k*k*(k+1)*(k+1)-t)/k)
	t=(k+1)*k
	k+=1