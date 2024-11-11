#  --*-coding:utf-8-*--


MOD = 998244353

def main():
    N = int(input())
    S = input()

    r,g,b = 0, 0, 0
    rg, rb, gb = 0, 0, 0
    empty=N

    x = 1
    for c in S:
        if c == 'R':
            if gb > 0:
                x = x*gb%MOD
                gb -= 1
            elif g > 0:
                x = x*g%MOD
                g -= 1
                rg += 1
            elif b > 0:
                x = x*b%MOD
                b -= 1
                rb += 1
            else:
                x = x*empty%MOD
                empty -= 1
                r += 1
        elif c == 'G':
            if rb > 0:
                x = x*rb%MOD
                rb -= 1
            elif r > 0:
                x = x*r%MOD
                r -= 1
                rg += 1
            elif b > 0:
                x = x*b%MOD
                b -= 1
                gb += 1
            else:
                x = x*empty%MOD
                empty -= 1
                g+= 1
        else:
            if rg > 0:
                x = x*rg%MOD
                rg -= 1
            elif r > 0:
                x = x*r%MOD
                r -= 1
                rb += 1
            elif g > 0:
                x = x*g%MOD
                g -= 1
                gb += 1
            else:
                x = x*empty%MOD
                empty -= 1
                b += 1

    print(x)
                

if __name__ == '__main__':
    main()
