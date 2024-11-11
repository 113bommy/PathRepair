def calcmod(base, pot, mod) :
    if pot <= 0:
        return 1
    # print("POT IS: " + str(pot))
    rec = calcmod(base, int(pot//2), mod)
    if int(pot%2) == 0:
        result = int((rec*rec)%mod)
        return result
    else :
        result = int((((rec*base)%mod)*rec)%mod)
        return result



def main():


    # up + down = 4^n
    # up - down = 2^n
    #
    # 2up = 4^n + 2^(n)
    #
    # TOTAL DE TRIANGULOS UPWARD::
    # up = 2^2n-1 + 2^n-1


    n = int(input())
    term1pot = 2*n - 1
    term2pot = n - 1
    base = 2
    mod = 1000000007

    # CALCULO DO MODULO::
    # (a+b)%m = (a%m + b%m) %m

    am = calcmod(base, term1pot, mod)
    bm = calcmod(base, term2pot, mod)
    result = int((am + bm)%mod)

    if n == 0:
        result = 1

    print(result)

if __name__ == '__main__':
    main()

# 1522506371688
