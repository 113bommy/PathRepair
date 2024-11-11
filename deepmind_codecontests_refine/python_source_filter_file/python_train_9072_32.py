while True:
    try:
        n = int(input())
        m = (n+2)//2
        print(m)
        for i in range(m):
            print('{0} {1}'.format(1,i+1))
        for i in range(1,n-m+1):
            print(m,i)
    except:
        break