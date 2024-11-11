for t in range(int(input())):
    n, d = [int(i) for i in input().split()]
    if d <= n:
        print("YES")
    elif (n-1)**2 + 4*(n-d) > 0:
        print("YES")
    else:
        print("NO")