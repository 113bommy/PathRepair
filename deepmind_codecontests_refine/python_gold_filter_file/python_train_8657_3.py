# problem https://codeforces.com/contest/1185/problem/D


def check(xs, i):
    del xs[i]
    if not xs or len(xs) <= 2:
        return True
    p = xs[1]
    d = xs[1] - xs[0]
    for x in xs[2:]:
        if x - p != d:
            return False
        p = x
    return True


if __name__ == '__main__':
    n = int(input())
    bs = list(map(int, input().split()))
    m = {}
    for i, b in enumerate(bs):
        m[b] = i + 1
    bs.sort()
    if check(bs[:], 0):
        print(m[bs[0]])
        exit(0)
    for i in range(1, n-1):
        if bs[i] - bs[i-1] != bs[i+1] - bs[i]:
            if check(bs[:], i - 1):
                print(m[bs[i - 1]])
            elif check(bs[:], i):
                print(m[bs[i]])
            elif check(bs[:], i+1):
                print(m[bs[i + 1]])
            else:
                print(-1)
            exit(0)

