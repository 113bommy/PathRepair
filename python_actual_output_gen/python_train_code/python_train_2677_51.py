for i in range(int(input())):
    X = list(map(int, input().split()))
    print("YES" if X[1] - X[0] > 1 else "NO")
