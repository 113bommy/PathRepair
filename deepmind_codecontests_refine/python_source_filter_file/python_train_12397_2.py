while True:
    x = list(map(int, input().split()))
    if x == y == 0:
        break
    print(min(x), max(x))