def main():
    def binpow(a, n):
	    res = 1
	    while(n):
		    if n % 2:
		        res = (res * a) % mod
		    a = (a * a) % mod
		    n //= 2
	    return res
    read = lambda: tuple(map(int, input().split()))
    mod = 1000000007
    def mul(a, b):
        v = a * b
        return v - mod if v > mod else v
    
    m, n, k = read()
    if m > n:
        m, n = n, m
    a = (m + n) - 1
    m -= 1
    d = m * (m + 1)
    
    c = a * m - d
    if 2 * m > a:
        c += 1
    #print(c, m, a)
    if m == 0 and n % 2 == 0 and k == -1:
        print(0)
    else:
        if c <= 0 or m == 0:
            print(1)
        else:
            print(binpow(2, c))
main()
