t = int(input())

def how_many(n, a):
    k = a.count(1)
    if k == 0:
        return n
    left = n - 1
    right = 0
    for i in range(n):
        if a[i] == 1:
            left = i
            break
    for i in range(n - 1, 0, -1):
        if a[i] == 1:
            right = i
            break
    if right == n - 1 or left == 0:
        return 2 * n
    else:
        return max(left, n - right - 1) * 2 + 2

for _ in range(t):
    n = int(input())
    a = list(map(int, input().strip()))
    print(how_many(n, a))
