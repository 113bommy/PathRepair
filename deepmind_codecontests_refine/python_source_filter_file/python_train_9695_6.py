n = int(input())
arr = [int(num) for num in input().split( )]
arr.sort()
a = 0
for i in range(0, 2, n):
    a += arr[i + 1] - arr[i]
print(a)     