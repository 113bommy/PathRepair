def main():
    t, k = map(int, input().split())
    mod = 1000000007
    l = [1] * 100001
    for i in range(k, 100001):
        a = l[i - 1] + l[i - k]
        l[i] = a - mod if a >= mod else a
    for i in range(1, 100001):
        a = l[i] + l[i - 1]
        l[i] = a - mod if a >= mod else a
    res = []
    for _ in range(t):
        a, b = map(int, input().split())
        a = l[b] - l[a - 1]
        res.append(a - mod if a >= mod else a)
    print('\n'.join(map(str, res)))


if __name__ == '__main__':
    main()