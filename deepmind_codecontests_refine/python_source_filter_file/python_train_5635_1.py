for i in range(int(input())):
    n,k=[int(i) for i in input().split()]
    if n>30:
        print('YES '+str(n-1))
    else:
        rez=-1
        for i in range(1,n+1):
            x=(4**i-2**(i+1)+1)*((4**(n-i)-1)//3)+(4**i-1)//3
            y=(4**i-1)//3-(4**(i-1)-1)//3
            if y<=k<=x:
                rez=n-i
                break
        print('YES '+str(rez) if rez!=-1 else 'NO')