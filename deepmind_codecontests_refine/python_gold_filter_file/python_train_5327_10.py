for i in range(int(input())):
    n, s, t = map(int, input().split())
    print(max(n-s, n-t) + 1)