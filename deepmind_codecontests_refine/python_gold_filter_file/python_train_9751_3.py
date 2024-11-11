n = int(input())
arr = []
for _ in range(n):
	arr.append(list(map(int,input().split())))
m = int(input())
for _ in range(m):
	arr.append(list(map(int,input().split())))
arr.sort(key = lambda x:x[0])
val = 0
i = 0
while(i < (len(arr)-1)):
	if(arr[i][0] == arr[i+1][0]):
		val += max(arr[i][1],arr[i+1][1])
		i += 2
	else: 
		val += arr[i][1]
		i +=1
if(len(arr)>1):
	if(arr[len(arr)-1][0] != arr[len(arr) - 2][0]):
		val += arr[len(arr)-1][1]
else:
	val += arr[0][1]
print(val)