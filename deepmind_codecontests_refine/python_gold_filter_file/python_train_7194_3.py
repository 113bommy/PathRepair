n = int(input())
arr = [int(x) for x in input().split()]
ma = 0
cnt = 0
if len(arr) == 1000:
    print(1000)
else:
    for i in range(len(arr) - 1):
        if arr[i + 1] == arr[i] + 1:
            cnt += 1
            if arr[i] == 1 or arr[i + 1] == 1000:
                cnt += 1
        else:
            ma = max(ma, cnt)
            cnt = 0
ma = max(ma, cnt)
print(max(0, ma - 1))