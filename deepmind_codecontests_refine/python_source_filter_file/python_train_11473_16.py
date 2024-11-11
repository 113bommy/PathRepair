for i in range(int(input())):
    X, Check = list(map(int, input().split())), True
    for j in range(2, min(X) // 2 + 1):
        if X[0] % j == 0 and X[1] % j == 0:
            Check = False
            break
    print("Infinite" if not Check else "Finite")
