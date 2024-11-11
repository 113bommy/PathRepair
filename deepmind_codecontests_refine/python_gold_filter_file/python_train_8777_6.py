for _ in range(int(input())):
    n,a,b = [int(x) for x in input().split()]
    if a == 1:
        if (n-1)%b == 0:
            print("YES")
        else:
            print("NO")
    else:
        x = 1
        ch = True
        while (x<=n):
            if (n-x)%b == 0:
                ch = False; break
            x*=a
        if ch:
            print("NO")
        else:
            print("YEs")