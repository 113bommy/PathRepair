for _ in range(int(input())):
    n, m = map(int, input().split())
    if n < m or n % m:
        print("NO")
    else:
        print("YES")