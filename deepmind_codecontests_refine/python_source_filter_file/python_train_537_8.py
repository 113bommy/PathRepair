cases = int(input())
for _ in range(cases):
    n, k, d = map(int, input().split())
    arr = list(map(int, input().split()))
    best = 10**10

    for i in range(n-d+1):
        ans = min(len(set(arr[i:d+i])), best)

    print(ans)