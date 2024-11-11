t = int(input())
for i in range(t):
    b, p, f = [int(i) for i in input().split()]
    h, c = [int(i) for i in input().split()]
    if h >= c:
        if b // 2 <= p:
            s = b // 2 * h
        else:
            s = p * h + min((b - p*2)//2,f) * c
    else:
        if b // 2 <= f:
            s = b // 2 * c
        else:
            s = f * c + min((b - f*2)//2, p) * h
    print(s)
