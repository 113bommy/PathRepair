for _ in range(int(input())):
    n = int(input())
    if n < 4:
        print(-1,end='')
    else:
        p = []
        for i in range(n,-1,-1):
            if i % 2 == 1:
                p.append(i)
        p.append(4);p.append(2)
        for i in range(6,n,2):
            p.append(i)
        for i in p:
            print(i, end = ' ')
    print()

'''
13
13 9 7 11 8 4 1 3 5 2 6 10 12

1 3 5  2 4 6  9 7 11  13 8 12  10
'''
