n = int(input())
def isPrime(n):
    for i in range(2, int(n**0.5)+1):
        if n%i==0:
            v = [i, False]
            return v
    v = [1, True]
    return v
s = isPrime(n)
if s[1] or n==1:
    print(n)
else:
    k = n
    i = 2
    ok = True
    while i * i <= k and ok:
        if k % i == 0:
            while k % i == 0:
                k = k / i
            ok = False
        i = i + 1
    if k==1:
        print(n//s[0])
    else:
        print(1)
