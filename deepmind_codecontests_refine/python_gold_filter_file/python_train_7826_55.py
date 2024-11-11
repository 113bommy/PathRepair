for i in range(int(input())):
    X = list(map(int, input().split()))
    print("YES" if X[0] - X[1] > 1 else "NO")
