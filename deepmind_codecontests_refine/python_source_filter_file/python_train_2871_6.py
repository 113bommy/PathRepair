n = int(input())
arr = input().split()
    
for i in range(0, n//2, 2):
    arr[i], arr[n-1-i] = arr[n-1-i], arr[i]

for i in arr:    
    print(arr)