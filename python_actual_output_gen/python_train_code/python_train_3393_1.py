# import sys
# sys.stdin = open('in', 'r')


def check(m, y):
    vis = [False]*n
    count = 0
    for i in range(n):
        if (lst[i] - y) == m * (i):
            count += 1
            vis[i] = True

    if count == n:
        return False
    if count == n - 1:
        return True

    pos = vis.index(False)

    for i in range(pos+1, n):
        if vis[i] and (lst[i] - lst[pos]) != m*(i-pos):
            return False

    return True


n = int(input())
lst = list(map(int, input().split()))

ans = False

ans |= check(lst[1]-lst[0], lst[0])
ans |= check(0.5 * (lst[2]-lst[0]), lst[0])
ans |= check(lst[2]-lst[1], 2 * lst[1] - lst[2])

print("Yes" if ans else "No")
