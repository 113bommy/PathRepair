for _ in range(int(input())):
    n, m = map(int, input().split())
    a = list(map(int, input().split()))
    if sum(a) == n:
        print("YES")
    else:
        print("NO")    