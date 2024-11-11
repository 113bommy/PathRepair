for t in range(int(input())):
    a1, k = map(int, input().split())
    for i in range(min(k - 1, 20)):
        a1 = a1 + (int(min(str(a1))) * int(max(str(a1))))
    print(a1)
