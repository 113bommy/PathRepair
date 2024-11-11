n, k, s = map(int, input().split())

if s == 10**9:
    ans = [s]*k + [1]*(n-k)
else:
    ans = [s]*k + [10**9]*(n-k)

print(ans)