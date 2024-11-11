for _ in range(int(input())):
    n, k = map(int, input().split())
    if n == 1 or k == 1 or(n == 2 or k == 2):
        print("YES")
    else:
        print("NO")
