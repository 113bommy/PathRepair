n=int(input())
lst=list(map(int,input().split()))
count=lst[0]
for i in range(n-2):
	if lst[i]<lst[i+1]:
		count+=lst[i+1]-lst[i]
	else:
		lst[i+1]+=lst[i]-lst[i+1]

		
print(count)