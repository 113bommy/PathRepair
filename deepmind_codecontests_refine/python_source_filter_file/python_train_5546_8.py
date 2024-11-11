t = int(input())
while t > 0:
    t-=1
    n = int(input())
    s = input()
    s = s.split()
    a = [int(i) for i in s] 
    a = sorted(a)
    ans = -1000000000000000
    prod = 1
    for i in range (6):
        prod = 1
        ta = a[:i]
        tb = a[ len(a)-5+i  :len(a)]
        for no in ta:
            prod*=no
        for no in tb:
            prod*=no
        if prod > ans:
            ans = prod
    print(int(ans))
                