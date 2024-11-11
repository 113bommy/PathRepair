# https://codeforces.com/contest/1326/problem/C

MOD = 998244353
def main():
    n, k = map(int, input().split())
    p = list(map(int, input().split()))
    t = n-k+1   # >=t を使う
    x = (n + t)*k//2
    y = 1
    tmp = 1
    flg = False
    for i in range(n):
        if p[i] >= t:
            if flg:
                y *= tmp
                y %= MOD
            else:
                flg = True
            tmp = 1
        else:
            tmp += 1
    print(x, y)

main()
