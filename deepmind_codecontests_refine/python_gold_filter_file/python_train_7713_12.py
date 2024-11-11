s = input()
if len(s) == 1:
    print(0)
else:
    n = sum(map(int, list(s)))
    res = 1
    while n >= 10:
        t = 0
        while n > 0:
            t += n%10
            n//= 10
        res += 1
        n = t
    print(res)
