for _ in range(int(input())):
    n = int(input())
    a = list(map(int,input().split()))
    count,cnt = a.count(1),a.count(0)

    if count==cnt:
        print(n//2)
        lst = [1]*(n//2)
        print(*lst,sep = ' ')
    elif count>cnt:
        if count%2==0:
            lst = [1]*count
            print(len(lst))
            print(*lst,sep = ' ')
        else:
            lst = [1]*(count-1)
            print(len(lst))
            print(*lst,sep = ' ')
    else:
        if cnt%2==0:
            lst = [0]*cnt
            print(len(lst))
            print(*lst,sep = ' ')
        else:
            lst = [0]*(cnt-1)
            print(len(lst))
            print(*lst,sep  = ' ')
