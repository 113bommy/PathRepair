n = int(input())
for a in range(1,3501):
    for b in range(1,3501):
        if 4*a*b-n*a-n*b == 0:
            continue
        if 1 <= n*a*b//(4*a*b-n*(a+b)) <= 3500 and (n*a*b)%(4*a*b-n*a-n*b) == 0:
            print(a,b,n*a*b//(4*a*b-n*(a+b)))
            exit()
