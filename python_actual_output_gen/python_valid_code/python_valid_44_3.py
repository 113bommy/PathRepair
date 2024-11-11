n = int(input())
for i in range(n):
    l, r = map(int, input().split())
    if (r - l - 1) % 2:
        if l % 2:
            print((r - l) // 2 - r)
        else:
            print(r - (r - l) // 2)
    else:
        if l % 2:
            print((r - l + 1) // 2)
        else:
            print((l - r + 1) // 2)
