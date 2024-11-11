#!/usr/bin python3
# -*- coding: utf-8 -*-

def main():
    mod = 10**9+7
    K = int(input())
    S = input()
    Nk = len(S)
    ret = 0
    nCk = 1
    pw25 = 1
    pw26 = pow(26,K,mod)
    inv26 = pow(26,mod-2,mod)
    for i in range(K+1):
        ret += nCk * pw25 * pw26
        ret %= mod
        nCk *= (i+Nk) * pow(i+1,mod-2,mod)
        nCk %= mod
        pw25 = (pw25*25)%mod
        pw26 = (pw26*inv26)%mod

    print(ret)

if __name__ == '__main__':
    main()
