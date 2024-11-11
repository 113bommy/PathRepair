s = input().split(" ")
n, m = int(s[0]), int(s[1])

# checkerboard battern
if(m % 2 == 0 and (m > (n*n)/2)):
    print("NO")
elif (m > (n*n)/2 + 1):
    print("NO")
else:

    print("YES")
    q = 1
    k = 0
    for i in range(1, n+1):
        for j in range(n):
            if(q) and m:
                print("L", end="")
                q = not q
                m -= 1
            else:
                print("S", end="")
                q = not q
        print()
        if(n % 2 == 0):
            q = not q
