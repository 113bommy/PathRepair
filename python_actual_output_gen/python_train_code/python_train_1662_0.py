from sys import stdin, stdout
input = stdin.readline
print = stdout.write


n = int(input())
a = list(map(int, input().split()))


def solve(n, a):
    l = -1
    s = set()
    while l + 1 < n and a[l + 1] not in s:
        s.add(a[l + 1])
        l += 1

    r = n
    while r - 1 >= 0 and a[r - 1] not in s:
        s.add(a[r - 1])
        r -= 1

    res = l + 1 + (n - r)
    while l >= 0:
        s.remove(a[l])
        l -= 1
        while r - 1 >= 0 and a[r - 1] not in s:
            s.add(a[r-1])
            r -= 1
        res = max(res, l + 1 + n - 4)
    return res

print(str(n - solve(n, a)))
