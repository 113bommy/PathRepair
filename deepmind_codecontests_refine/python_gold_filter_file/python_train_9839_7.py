t = int(input())
while (t > 0):
    n = int(input())
    s = n*(n+1)//2
    i = 1
    t -= 1
    while (i <= n):
        s -= 2*i
        i *= 2
    print(s)