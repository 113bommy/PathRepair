for t in range(int(input())):
    n, d = [int(i) for i in input().split()]
    if d <= n:
        print("YES")
    elif (1-n)**2 - 4*(d-n) >= 0:
        print("YES")
    else:
        print("NO")