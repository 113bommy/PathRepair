t, s, x = input().split()
t, s, x = int(t), int(s), int(x)

if t == x:
    print("YES")
else:
    t += s

    if (t >= x):
        print("NO")
    else:
        x = x - t

        jumps = x // s

        t1 = jumps * s
        t2 = t1 + 1

        if t1 == x or t2 == x:
            print("YES")
        else:
            print("NO")