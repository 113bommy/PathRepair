a=[0,45,40,45,40,25,40,45,40,45]
for _ in range(int(input())):
    n,m=map(int,input().split())
    mm=m%10#4
    
    quo=n//m#73
    #print(quo)
    qq1=quo%10#3
    #print(qq1)
    qq2=(quo-qq1)//10#7
    print(qq2)
    sum=qq2*a[mm]#45*3
    print(sum)
    for i in range(1,qq1+1):
        sum+=((mm*i)%10)
        print(sum)
    print(int(sum))
    