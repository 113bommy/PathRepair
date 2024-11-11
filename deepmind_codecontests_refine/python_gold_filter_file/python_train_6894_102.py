for _ in range(int(input())):
    li = list(map(int, input().split()))
    m = li[0]
    n = li[1]
    if m % n == 0:
        print("YES")
    else:
        print("NO")