n=int(input())
count=0
for i in range(1,1+n//2):
	if (n-i)%i==0:
		count+=1
print(count) 