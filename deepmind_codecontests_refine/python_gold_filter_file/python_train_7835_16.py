t = int(input())
for _ in range(t):
    n = int(input())
    a = [int(s) for s in input().split()]
    s = sum(a)
    if s == 0:
        print("NO")
    else:
        print("YES")
        if s > 0:
            a.sort(reverse=True)
            print(*a)
        else:
            a.sort()
            print(*a)
