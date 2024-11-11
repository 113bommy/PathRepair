def solve():
    if a[0] != 0:
        return 1

    r = 0
    for i in range(n):
        if a[i] != 0 and a[i] > r+1:
            return i + 1
        else:
            r = max(r, a[i])
    return -1

n = int(input())
a = list(map(int, input().split()))
print(solve())
