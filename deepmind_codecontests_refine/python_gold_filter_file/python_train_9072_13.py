n=int(input())
if n%2==0: m=n//2+1
else: m=(n+1)//2
j,k=1,1
print(m)
for i in range(1,n+1):
	if i%2!=0:
		print(j,j)
		j+=1
	else:
		print(k,k+1)
		k+=1
	