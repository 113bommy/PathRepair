k = int(input())

if k > 36:
    print(-1)
else:
    if k > 0:
        print("8" * (k // 2) + "6" * (k % 2))
    else:
        print("1")