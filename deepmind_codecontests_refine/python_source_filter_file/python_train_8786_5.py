m = int(input())
arr = list(map(int, input().split()))
x,y  = map(int, input().split())
 
for i in range(1,m):
	arr[i] += arr[i-1]

total = arr[-1]


for i in range(m):
	if x<= arr[i] <= y and x<= total - arr[i] <= y:
		ans = i+1
		print(ans)
		exit()
print(0)