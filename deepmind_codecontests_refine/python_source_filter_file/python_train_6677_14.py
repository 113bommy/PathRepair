try:
    N=int(input())
    for v in range(N):
        n,a,b=[int(val) for val in input().split()]
        x1=a
        x2=b/2
        if x1 <= x2:
            print(x1*n)
        else:
            if n%2==0:
                print(int((n/2)*x2))
            else:
                print(int(((n-1)*x2)+a))
except:
    pass

    
