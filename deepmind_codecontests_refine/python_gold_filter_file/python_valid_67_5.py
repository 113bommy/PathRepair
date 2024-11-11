q = int(input())
while q != 0:
    a , b , c = map(int , input().split())
    if a > b:
        x = a
        a = b
        b = x
    if b - a >= a and c <= 2 * (b - a):
        if c <= b - a:
            print(b - a + c)
        else:
            print(c - (b - a))
    else:
        print(-1)
    q -= 1
                