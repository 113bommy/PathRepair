def solve(arr, n, k):
    f = 1
    for i in range(n - 1, -1, -1):
        if (arr[i] != arr[k - 1]):
            f = 0
            break
    if (i > k):
        return -1
    elif f:
        return (0)
    else:
        return i+1

n, k = map(int, input().split())
arr = list(map(int, input().split()))
print(solve(arr, n, k))

