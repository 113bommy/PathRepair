MOD = 1000000007

def calc(n, m, k):
    if k == -1 and n%2 != m%2:
        return 0
    n = (n-1)
    m = (m-1)
    n = (n * m) 
    r = 1
    s = 2
    while n > 0:
        if n % 2 == 1:
            r = (r*s) % MOD
        n /= 2
        s = (s*s) % MOD
    return r

if __name__ == '__main__':
    n, m, k = input().split(' ')
    print(calc(int(n), int(m), int(k)))
    