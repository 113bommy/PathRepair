def get_col(arr, i):
    return [row[i] for row in arr]


n, m = map(int, input().split())
arr, mod, ans = [input() for i in range(n)], 1000000007, 1

for i in range(m):
    ans *= len(set(get_col(arr, i))) % mod

print(ans)
