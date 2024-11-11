for _ in range(int(input())):
    l,r,m=map(int,input().split())
    for a in range(l,r+1):
        if (m % a == 0):
            c = r
            b = r - a
            print(a, l, l)
            break
        else:
            d = ((m // a) + 1) * a - m
            d1=m % a
            if (r - d >= l):
                print(a, r - d, r)
                break

            elif(r-d1>=l):
                print(a, r, r - d1)
                break

