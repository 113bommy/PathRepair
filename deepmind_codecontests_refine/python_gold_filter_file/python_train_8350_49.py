for i in range(int(input())):
    H, M = list(map(int, input().split()))
    print((23 - H) * 60 + (60 - M ))