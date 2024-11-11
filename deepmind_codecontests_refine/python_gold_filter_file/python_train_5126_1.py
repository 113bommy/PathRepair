t = int(input())

def solve(n, x, a):
    cnt = 0

    for i in range(1, n + x + 1):
        if i not in a:
            cnt += 1

        if cnt > x:
            return i - 1

    return x + n

for i in range(t):
    n, x = list(map(int, input().split()))
    a = list(map(int, input().split()))

    print(solve(n, x, a))

