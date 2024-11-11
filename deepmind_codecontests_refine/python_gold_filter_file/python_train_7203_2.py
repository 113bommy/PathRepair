for i in  range(int(input())):
    n = int(input())
    zr = on = odds = 0
    for i in range(n):
        s = input()
        if len(s)%2:
            odds += 1
        else:
            zr += s.count('0')
            on += s.count('1')
    if zr%2 and on%2 and odds==0:
        print(n-1)
    else:
        print(n)
