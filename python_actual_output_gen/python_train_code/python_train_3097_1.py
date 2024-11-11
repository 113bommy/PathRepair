N = int(input())
sum = 0
for i in range(N):
    arr = list(map(int, input().split()))
    sum += (arr[2] - arr[0] + 1) * (arr[3] - arr[0] + 1)
print(sum)