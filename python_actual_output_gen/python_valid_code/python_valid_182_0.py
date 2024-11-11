n,k = map(int,input().split(" "))

arr = list(map(int,input().split(" ")))

arr.append(k)

arr.insert(0,k)

print(arr)

extra = 0


for i in range(1,n+1):

	if(arr[i] + arr[i-1] < k):
		temp = arr[i]
		arr[i] = k - arr[i-1]

		extra += k - arr[i-1] - temp


print(extra)
print(*arr[1:-1])