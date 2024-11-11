n,k = input().strip().split(" ")
n,k = [int(n),int(k)]
arr = [int(arr_temp) for arr_temp in input().strip().split(' ')]
count = 0
for i in range(n):
    if arr[0] == 0:
        count = 0
        break
    if arr[i] >= arr[k-1] and arr[i] !=0:
        count+=1
print(count)