for _ in range(int(input())):
    n, k = map(int, input().split())
    arr = [*map(int, input().split())]
    mx = max(arr) if k&1 else min(arr)
    arr = [abs(mx - i) for i in arr]
    print(*arr)