n=int(input())
count=0
for i in range(1,n):
	if (n-1)%i == 0:
		count+=1
print(count)
