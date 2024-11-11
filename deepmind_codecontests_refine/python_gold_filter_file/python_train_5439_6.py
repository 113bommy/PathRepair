for _ in range(int(input())):
    n = int(input())
    if(n <= 9):
        print('1')
        print(n)
    else:
        temp = str(n)
        temp = temp[1:]
        flag = 0
        for i in range(len(temp)):
            if(temp[i] >  '0'):
                flag = 1
                break
        if(flag == 0):
            print('1')
            print(n)
        else:
            temp = n
            res = []
            count = 0
            while(temp):
                if(temp%10 == 0):
                    count += 1
                res.append(temp%10)
                temp //= 10
            prod = 1
            print(len(res)-count)
            for i in res:
                if(i != 0):
                    print(i*prod,end = " ")
                prod *= 10
            print('')