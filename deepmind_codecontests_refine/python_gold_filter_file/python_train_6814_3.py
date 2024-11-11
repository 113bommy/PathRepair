n = input()
n = int(n)
#print(n)
if (n < 46):
    a = 0
    while n:
        if (n >= 10):
            a = a * 10 + 9
            n -= 9;
        else:
            a = a * 10 + n
            n = 0
    print(a, a)
    exit(0)
p = 1
for i in range(1,n):
    p *= 10
    m = p // 10 * i * 45 + 1
    #print(m, p, m + p)
    if (m + p > n):
        k = n - m
        while k < 0:
            k += n
        if (k >= p):
            continue
        print(k + 1, p + k)
        exit(0)
    
