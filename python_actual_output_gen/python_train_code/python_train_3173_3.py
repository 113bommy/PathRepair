for _ in range(int(input())):
    x = int(input())
    if x%3==0 or x%7==0:
        print('YES')
    else:
        tmp = x//7
        flag = True
        while (x-tmp)%3!=0:
            tmp -= 7
            if tmp<=0:
                flag = False
                break
        if flag:
            print('YES')
        else:
            print('NO')