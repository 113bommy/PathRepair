for _ in range(int(input())):
    a, b = map(int, input().split(" "))
    mx = max(a, b)
    mn = min(a, b)
    if (mx+mn) % 3 == 0 and mx >= 2 * mn:
        print("YES")
    else:
        print("NO")