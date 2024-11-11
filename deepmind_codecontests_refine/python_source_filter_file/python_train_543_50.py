try:
    t=int(input())
    for i in range(t):
        n=int(input())
        sum=0
        if n==1 or n==3:
            print(0)
        else:
            p=1
            while n>3:
                sum=sum+p*(8*p)
                p=p+1
                n=n-2
            print(sum)

except Exception as e:
    pass
