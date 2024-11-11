t = int(input())
arr = []
for _ in range(t):
    arr.append(int(input()))


def solve(arr, n, s):
    if n < 0:
        if s == 360 or s == 0:
            return True
        return False
    res = solve(arr, n-1, s - arr[n]) | solve(arr, n-1, s + arr[n])
    return res
if solve(arr, len(arr) - 1, 0):
    print('YES')
else:
    print('NO')