#  =========     /\       /|    |====/|
#      |        /  \       |    |   / |
#      |       /____\      |    |  /  |
#      |      /      \     |    | /   |
#  ========= /        \  =====  |/====|  
#  code

def main():
    MOD = int(1e9 + 7)

    a = input()
    b = input()
    n = int(input())

    ca, cb = 0,0

    for i in range(len(a)):
        s = a[i:] + a[:i]
        if s == b:
            ca += 1
        else:
            cb += 1
    
    if ca == 0:
        print(0)
        return

    da = [0] * (n + 1)
    db = da[:]

    da[0] = 1 if a == b else 0
    db[0] = 1 - da[0]

    for i in range(1, n + 1):
        da[i] = da[i - 1] * (ca - 1) + db[i - 1] * ca
        db[i] = da[i - 1] * cb + db[i - 1] * (cb - 1)
        da[i] %= MOD
        db[i] %= MOD
        # print(da[i], db[i], ca, cb)
    print(da[n])
    return

if __name__ == "__main__":
    main()