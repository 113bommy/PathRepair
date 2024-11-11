querry = int(input())
for loop in range(querry):
    c, m, n = [int(i) for i in input().split()]
    if c == 0 or m == 0:
        print(0)
    else:
        smallest = None
        if c<m and c<n:
            smallest = 'c'
        elif m<c and m<n:
            smallest = 'm'
        elif m==c and c==n:
            print(m)
        elif m==c and m<n:
            print(m)
        else:
            smallest = 'n'
        if smallest == None:
            pass
        else:
            if smallest == 'c':
                print(c)
            elif smallest =='m':
                print(m)
            elif smallest =='n':
                c -= n
                m -= n
                if c==0 or m == 0:
                    print(n)
                else:
                    if c+m == 4 or c+m ==3 or c+m==5:
                        print(n+1)
                    elif c<m:
                        if c*2<=m:
                            print(n+c)
                        else:
                            teamNum = m-c
                            c -=teamNum
                            if c % 3 == 0 or c % 3 == 1:
                                print(n + (c // 3) * 2 + teamNum)
                            elif c % 3 == 2:
                                print(n + (c // 3) * 2 + 1 + teamNum)
                    elif c>m:
                        if 2*m<=c:
                            print(n+m)
                        else:
                            teamNum = c-m
                            m -=teamNum
                            if m % 3 == 0 or m % 3 == 1:
                                print(n + (m // 3) * 2 + teamNum)
                            elif m % 3 == 2:
                                print(n + (m // 3) * 2 + 1 + teamNum)
                    else:
                        if c%3 == 0 or c%3 == 1:
                            print(n+(c//3)*2)
                        elif c%3 == 2:
                            print(n+(c//3)*2+1)

