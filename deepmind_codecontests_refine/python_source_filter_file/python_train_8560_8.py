for _ in range(int(input())):
    x, n, m = map(int, input().split())
    for i in range(n):
        p = round(x/2) + 10
        if p < x:
            x = p
            continue
        else :
            break
    x = x - m*10
    if x <= 0:
        print("YES")
    else :
        print("NO")
