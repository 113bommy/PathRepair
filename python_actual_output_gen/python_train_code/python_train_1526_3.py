for t in range(int(input())):
    n = int(input())
    # a = list(map(str,input().split()))
    a = [j for j in input().split()]
    k = a.count('1')
    if k <= 1:
        print(0)
    else:
        h1 = a.index('1')
        a.reverse()
        h2 = a.index('1')
        print(a[h1 : len(a) - h1 ].count('0'))