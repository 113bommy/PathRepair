n=int(input())
for i in range(n):
	if i**2+i>=2*n:
		p=i
		break
total=(p*(p+1))//2
for i in range(1,p+1):
	if total-n!=i:
		print(i)