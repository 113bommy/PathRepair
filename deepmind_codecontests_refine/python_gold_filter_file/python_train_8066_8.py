left = 0
right = 0
arr = []
n = int(input())
for i in range (n):
    t, v = map(int, input().split(" "))
    arr.append([t, v])
    if arr[i][0] < 0:
        left+=1
    else:
        right+=1

arr = sorted(arr, key=lambda a: a[0])

sum = 0
if left < right:
    for i in range(2*left+1):
        sum += arr[i][1]
elif left == right:
    for i in range(2*left):
        sum += arr[i][1]
else:
    for i in range(left-right-1, left+right):
        sum += arr[i][1]
        
print(sum)



