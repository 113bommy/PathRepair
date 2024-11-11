from sys import stdin


def main():
    n, v = map(int, stdin.readline().strip().split())
    res = []
    for _ in range(n):
        l = list(map(int, stdin.readline().strip().split()))
        nn = l.pop(0)
        if any(e < v for e in l):
            res.append(nn)
    res.sort()
    print(len(res))
    print(*res)


main()
