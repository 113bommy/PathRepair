for i in range(int(input())):
    H, M = list(map(int, input().split()))
    print((H - 23) * 60 + (60 - M ))