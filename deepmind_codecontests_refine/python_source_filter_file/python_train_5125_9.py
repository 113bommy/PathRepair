t = int(input())
for _ in range(t):
    n, d = map(int, input().split())
    arr = list(map(int, input().split()))
    pos = 1
    while d and pos<n:
        if arr[pos] == 0:
            pos += 1
            continue
        if d - pos <= 0:
            break
        arr[pos] -= 1
        arr[0] += 1
        d -= pos
    print(arr[0])

