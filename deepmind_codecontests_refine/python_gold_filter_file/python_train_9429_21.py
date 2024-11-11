# C[n+1] = sum(C[i]*C[n-i]) 0 <= i <= n
# C[0] = 1
t = int(input())
arr = sorted([int(p) for p in input().split()])
for i in range(len(arr)-2):
    if arr[i] + arr[i+1] > arr[i+2]:
        print('YES')
        exit()
print('NO')
