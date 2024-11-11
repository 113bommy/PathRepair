def singer(n,d,array):
    sing_time=sum(array)
    remain_time=d-sing_time
    if remain_time%5==0:
        jokes_time_btw=(n-1)*2*5
        if remain_time-jokes_time_btw>=0:
            extra_jokes=(remain_time-jokes_time_btw)/5
            total_jokes=extra_jokes+2*(n-1)
            print(int(total_jokes))
        else:
            print(-1)

    else:
        print(-1)
n,d=input().split()
array=[int(x) for x in input().split()]
singer(int(n),int(d),array)
