for _ in range(int(input())):
    n = int(input())
    arr = list(map(int, input().split()))
    arr = sorted(arr)
    n+=2
    pref = [0 for _ in range(n)]
    pref[0] = arr[0]
    for k in range(1, n):
        pref[k]+=arr[k]+pref[k-1]
    if pref[n-3]==arr[n-2]:
        print(*arr[:(n-2)])
    elif pref[n-2] > arr[n-1] and pref[n-2]-arr[n-1] in arr[:(n-1)]:
        res = arr[:(n-1)]
        res.remove(pref[n-2]-arr[n-1])
        print(*res)
    else:
        print("-1")