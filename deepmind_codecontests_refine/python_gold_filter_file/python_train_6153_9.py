n, d = input().split()
n = int(n)
d = int(d)

m = int(input())
for i in range(0, m):
    x, y = input().split()
    x = int(x)
    y = int(y)

    if (x+y) < d:
        print("NO")      # ALPHA
    elif x > (d+y):
        print("NO")      # BRAVO
    elif (x+y) > (2*n-d):
        print("NO")    # CHARLIE
    elif x < (y-d):
        print("NO")      # DELTA
    else:
        print("YES")
