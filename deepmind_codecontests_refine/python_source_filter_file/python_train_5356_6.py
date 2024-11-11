def main():
    r = lambda: tuple(map(int, input().split()))
    n, p = r()
    x = set()
    for i in range(n):
        d = r()[0] % p
        if d in x:
            print(i + 1)
            return
        else:
            x.add(d)
    print(-1)
main()