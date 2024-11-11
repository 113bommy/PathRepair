n=int(input())
m=1
if n%2==0 or n==1:
	for i in range(2,100):
		for j in range(2,(n*i+1)//2+1):
			if (n*i+1)%j==0:
				m=i
				break
		if m!=1:
			break		
print(m)