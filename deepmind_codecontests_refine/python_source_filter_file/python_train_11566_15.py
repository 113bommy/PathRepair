n = int(input())
arr = list(map(int, input().split()))
res = []

if arr.count(arr[0]) == n:
    print(n)
    print(" ".join(str(e) for e in arr))
else:
    for i in range(n-1):
        if arr[i+1] < arr[i]:
            res.append(arr[i])
        else:
            continue

    res.append(arr[n-1])
    print(len(res))
    print(" ".join(str(e) for e in res))

