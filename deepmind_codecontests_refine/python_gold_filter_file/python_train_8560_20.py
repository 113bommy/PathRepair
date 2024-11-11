def dragonQuest(x, n, m):
    if x <= 0:
        print('YES')
        return True

    if n > 0:
        x = (x//2) + 10
        return dragonQuest(x, n-1, m)
    if m > 0:
        x = x - 10
        return dragonQuest(x, n, m-1)


def main():
    t = int(input())
    for i in range(t):
        x, n, m = tuple(map(int, input().split()))
        if x-(m*10) <= 0:
            print('YES')
        elif not dragonQuest(x, n, m):
            print('NO')
main()
