n = int(input())
num = list(map(int, input().split()))
num.sort()
arr = []
for i in range(n - 1):
    arr.append(num[i + 1] - num[i])

minn = 1000000000
for i in range(n - 1):
    if arr[i] < minn:
        minn = arr[i]

ans = arr.count(minn)
print(minn, ans)
