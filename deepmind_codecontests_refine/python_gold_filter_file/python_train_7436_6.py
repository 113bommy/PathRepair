n, k = [int(x) for x in input().split()]

slogan = input()

if k <= n / 2:
    if k != 1:
        for x in range(k-1):
            print("LEFT")
        for x in (range(n)):
            print("PRINT " + slogan[x])
            if x != n - 1:
                print("RIGHT")
    else:
        for x in (range(n)):
            print("PRINT " + slogan[x])
            if x != n - 1:
                print("RIGHT")
else:
    if k != n:
        for x in range(n - k):
            print("RIGHT")
        for x in reversed(range(n)):
            print("PRINT " + slogan[x])
            if x != 0:
                print("LEFT")
    else:
        for x in reversed(range(n)):
            print("PRINT " + slogan[x])
            if x != 0:
                print("LEFT")
