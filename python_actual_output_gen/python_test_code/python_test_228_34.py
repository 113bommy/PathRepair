t = int(input())
for _ in range(t):
    a,b = map(int, input().split(" "))
    z = 0
    if a == b:
        print(0)
    else:
        x = abs(a - b)
        if x > 10:
            z += x // 10
            x -= (x // 10) * 10
            if x!=0:
                z += 1
        else:
            z += x
        print(z)