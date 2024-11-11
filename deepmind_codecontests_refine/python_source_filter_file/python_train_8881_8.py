for __ in range(int(input())):
    n = int(input())
    a = list(map(int, input().split()))
    b = list(map(int, input().split()))
    add, sub = 0, 0
    x, y = [], []
    for i in range(n):
        if a[i] < b[i]:
            for j in range(b[i] - a[i]):
                x.append(i)
        elif a[i] > b[i]:
            for j in range(a[i] - b[i]):
                y.append(i)
    if len(x) != len(y):
        print(-1)
    else:
        print(len(x))
        for i, j in zip(x, y):
            print(i+1, j+1)
