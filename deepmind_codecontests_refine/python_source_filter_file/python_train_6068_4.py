def answer():

    dec,m=0,a[0]
    for i in range(1,n):
        if(a[i - 1] < a[i]):
            dec = (a[i] - a[i - 1])

        m=min(m,a[i] - dec)

        if(m < 0):return 'NO'

    return 'YES'
    


for T in range(int(input())):

    n=int(input())

    a=list(map(int,input().split()))


    print(answer())
