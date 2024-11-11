def main():
    t = int(input())
    for __ in range(t):
        m = int(input())
        pres = 1
        req = 0
        a = sorted(list(map(int,input().split())))
        for i in range(m):
            if (i+1) >= a[i] and req > 0:
                req -= 1
            elif (i+1) < a[i]:
                if req > 0:
                    req -= 1
                req += (a[i]-(i+1))
            if req == 0:
                pres = i+2
        print(pres)
if __name__ == '__main__':
    main()
