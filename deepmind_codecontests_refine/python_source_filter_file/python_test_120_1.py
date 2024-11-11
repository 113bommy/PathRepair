def fun(n):
    n += 1
    i = 2
    arr = [0 for i in range(32)]
    j = 32
    while n >= i:
        j -= 1
        x = (n // i)*(i//2)
        if (n % i) > i//2:
            x += ((n % i) - i//2)
        arr[j] = x
        i = i*2
    return arr
for _ in range(int(input())):
    l, r = map(int, input().split())
    a = fun(r)
    b = fun(l)
    # print(a)
    # print(b)
    for i in range(32):
        a[i] -= b[i]
    print(r+1 - l - max(a))