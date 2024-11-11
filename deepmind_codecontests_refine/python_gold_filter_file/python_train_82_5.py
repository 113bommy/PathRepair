from fractions import gcd
T = int(input())

for _ in range(T):
    a, b, c, d = map(int, input().split())
    if b > a or b > d:
        flg = False
    else:
        if b - 1 <= c:
            flg = True
        elif a % b > c:
            flg = False
        else:
            g = gcd(d, b)
            if (b - 1 - a % b) // g * g + a % b <= c: 
                flg = True
            else:
                flg = False

    if flg:
        print("Yes")
    else:
        print("No")

