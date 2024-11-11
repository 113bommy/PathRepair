t, s, x = map(int, input().split())
if (x < t):
    print("NO")
else:
    x = x - t
    if ((x % s == 0) or (x % s == 1)) and (x != 1):
        print("YES")
    else:
        print("NO")