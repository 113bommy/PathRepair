def main():
    n = int(input())
    g = [[] for _ in range(n)]
    for v in range(1, n):
        g[int(input()) - 1].append(v)
    for vv in g:
        if vv and sum(not g[v] for v in vv) < 3:
            print('No')
            return
    print('Yes')


if __name__ == '__main__':
    main()
