n = int(input())
arr = input().split()
for i in range(n):
    arr[i] = int(arr[i])

arr.sort()
arr.reverse()
for i in range(n-2):
    if arr[i] < arr[i-1] + arr[i-2]:
        print("YES")
        exit()

print("NO")