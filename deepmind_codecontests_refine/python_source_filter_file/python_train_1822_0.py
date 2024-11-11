def main():
    read = lambda: tuple(map(int, input().split()))
    n = read()[0]
    l = read()
    ans = [0] * (n + 1)
    was = [0] * (n + 1)
    c = 0
    for i, v in enumerate(l):
        if v >= 1 and v <= n and not was[v]:
            was[v] = 1
            ans[i + 1] = v
            
    j = 0
    for v in range(1, n + 1):
        if not was[v]:
            while ans[j] != 0:
                j += 1
            ans[j] = v
    print(*ans[1:])
main()
