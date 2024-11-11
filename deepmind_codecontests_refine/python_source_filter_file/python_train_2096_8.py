


t = int(input())

while t!=0:

    ang = int(input())
    f=0
    ans=-1
    for n in range(3,181):
        for k in range(1,n-1):
            # if n==90:
            #     print((180/n)*k)

            if (180/n)*k == ang:
                # print(n,k)
                ans=n
                f=1
                break
        if f==1:
            break
    print(ans)




    t-=1
