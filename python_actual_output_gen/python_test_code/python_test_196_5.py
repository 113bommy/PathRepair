n, m = map(int, input().split())
arr = list(map(int, input().split()))

if n >= m:
    print(0)
else:
    new_arr = []
    for x in range(n):
        for y in range(x+1, n):
            new_arr.append(abs(arr[x]-arr[y]) % m)
    ans = 1
    for each in new_arr:
        ans = (ans*each) % m
    print(ans)

