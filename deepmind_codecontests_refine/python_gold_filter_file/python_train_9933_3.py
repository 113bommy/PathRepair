n, k = map(int, input().split())
arr = list(map(int, input().split()))

if k == 1:
    mn = float('inf')
    for i in range(n):
        if arr[i] < mn:
            mn = arr[i]
            ind = i
else:
    mn = float('inf')
    sm = 0
    ind = 0
    for i in range(n):

        if i > k - 1:
            sm += arr[i]
            sm -= arr[i-k]
        else:
            sm += arr[i]

        if i >= k - 1:
            if sm < mn:
                mn = sm
                ind = i - (k - 1)


print(ind+1)