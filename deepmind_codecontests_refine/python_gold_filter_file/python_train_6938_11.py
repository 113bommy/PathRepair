n = int(input())
for x in range(n):
    x = int(input())
    if x == 0:
        print(1, 1)
    else:
        flag = True
        for d in range(1, int(x**0.5)+1):
            if x % d == 0:
                s = x // d
                n = (s + d)//2
                if int(n) != n:
                    continue
                nm = s - n
                if nm <= 0:
                    continue
                m = n//nm
                if (m>0) and (n**2 - (n//m)**2 == x):
                    print(n, m)
                    flag = False
                    break
        if flag:
            print(-1)