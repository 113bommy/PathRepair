n = int(input())
arr = [int(i) for i in input().split()]
totalseats = sum(arr)
required = totalseats//2
ans = [1]
curtotal = arr[0]
for i in range(1,n):
	if(curtotal <= required and arr[0]>=2*arr[i]):
		ans.append(i+1)
		curtotal += arr[i]
if(curtotal > required):
	print(len(ans))
	for i in ans:
		print(i,end= " ")
else:
	print(0)