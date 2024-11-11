#  =========     /\       /|    |====/|
#      |        /  \       |    |   / |
#      |       /____\      |    |  /  |
#      |      /      \     |    | /   |
#  ========= /        \  =====  |/====|  
#  code

def main():
    p = 1
    l = 0
    n,d = map(int, input().split())

    for i in range(19):
        p *= 10
        k = (n % p - n % (p // 10)) / (p // 10)
        if l == 1:
            if k == 0:
                k = 9
            else:
                k -= 1
                l = 0
        
        if k == 9:
            n -= (n % p - n % (p // 10))
            n += (p // 10) * 9
            continue
        else:
            if (p // 10) * (k + 1) <= d:
                d -= (p // 10) * (k + 1)
                n -= (n % p - n % (p // 10))
                n += (p // 10) * 9
                l = 1
            else:
                n -= (n % p - n % (p // 10))
                n += (p // 10) * k
                break
    print(n)
    return

if __name__ == "__main__":
    main()