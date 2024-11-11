for _ in range(int(input())):
    l, r = map(int, input().split())
    print("YES" if r/l < 2 else "NO")
