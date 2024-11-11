t = int(input())
while t:
    n = int(input())
    a = list(map(int, input().split()))
    c = 0
    for i in range(n):
        if(a[i] <= 0):
            if(abs(a[i]) <= c):
                c += a[i]
                a[i] = 0
            else:
                a[i] += c
                c = 0
        else:
            c = a[i]
    c = 0
    # print(a)
    for i in range(n):
        if(a[i] < 0):
            c -= (a[i])
    print(c)
    t -= 1
