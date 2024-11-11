def solve(w, a, b):
    q = list()
    for i in w:
        k = (i * a) % b
        q.append(k // a)
    return q


if __name__ == '__main__':
    n, a, b = map(int, input().split())
    w = map(int, input().split())
    res = map(str, solve(w, a, b))
    print(' '.join(res))
