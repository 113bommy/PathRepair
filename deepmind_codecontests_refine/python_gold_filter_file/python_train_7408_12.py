n = int(input())

if n % 2 != 0:
    print(0)
else:
    buf = n//2
    res = 2**buf
    print(res)
