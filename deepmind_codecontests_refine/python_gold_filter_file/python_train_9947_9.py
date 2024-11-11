t, s, x = map(lambda x: int(x), input().split())
if x < t:
    print("NO")
else:
    x -= t
    if x in [1]:
        print("NO")
    else:
        x %= s
        if x in [0,1]:
            print("YES")
        else:
            print("NO")
