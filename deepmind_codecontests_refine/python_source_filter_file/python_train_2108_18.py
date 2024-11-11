import math

def find(n):
	ct=0
	while(n>0):
		n//=2
		ct+=1
	return ct




arr=[1]*32
for i in range(1,32):
	arr[i]=2*arr[i-1]
# print(arr)

for t in range(int(input())):
	
	ans=[1]
	n = int(input())
	if n==2:
		ans.append(1)
	elif n==3:
		ans.append(2)
	else:
		sum=0
		target=n-1
		length=find(n)
		for i in range(1,length-2):
			sum+=arr[i]
			ans.append(arr[i])

		required = target-sum
		print(required,sum)

		no1 = max(ans[-1],math.ceil(required/3))
		no2 = required-no1
		ans.append(no1)
		ans.append(no2)

	print(len(ans)-1)
	for i in range(1,len(ans)):
		print(ans[i]-ans[i-1],end=" ")
	print()