while True:
    try:
        n = int(input())
        m = (n+2)//2
        print(m)
        for i in range(m):
            print('{0} {1}'.format(1,i+1))
        for i in range(2,n-m+2):
            print(i,m)
    except:
        break