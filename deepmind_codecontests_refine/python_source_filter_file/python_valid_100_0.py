def sol():
    n = int(input())
    arr = [int(x) for x in input().split()]
    m = 998244353
    fact = (n+1)*[0]
    fact[0] = 1
    for i in range(1,n+1):
        fact[i] = (fact[i-1]*i)%m
    if n == 1:
        return 1
    cnt = dict()
    maksi = 0
    for el in arr:
        cnt[el] = cnt.get(el, 0) + 1
        maksi = max(maksi, el)
    if cnt[maksi] != 1:
        return fact[n]
    if (maksi - 1) not in cnt:
        return 0
    rozne = cnt[maksi-1]
    inne = n - 1 - rozne
    lewa = 1
    ans = 0
    for i in range(n,rozne,-1):
        ans = (ans + fact[rozne+inne] * lewa) % m
        lewa = (lewa * inne) % m
        inne -= 1
    return fact[n] - ans

def main():
    for i in range(int(input())):
        print(sol())

main()
        
