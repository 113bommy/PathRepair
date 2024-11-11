n = int(input())

for _ in range(n):
    _ = int(input())
    arr = list(map(int, input().split()))

    if arr[0] + arr[1] < arr[-1]:
        print(1, 2, len(arr))
    else:
        print(-1)