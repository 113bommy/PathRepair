def check(a, b, c, d):
    return a==d and b==c
for _ in range(int(input())):
    n, m = map(int, input().split())
    if m & 1:
        for i in range(n):
            a, b = map(int, input().split())
            c, d = map(int, input().split())
        print("NO")
        continue
    flag = 0
    for i in range(n):
        a, b = map(int, input().split())
        c, d = map(int, input().split())
        if check(a, b, c, d):
            flag = 1
    print("YES") if flag else print("NO")