for _ in range(int(input())):
    n = int(input())
    s = str(input())
    if n % 2 == 0:
        flag = False
        for i in range(0,n,2):
            if int(s[i]) % 2 == 0:
                flag = True
                break
        if flag:
            print(2)
        else:
            print(1)
    else:
        flag = False
        for i in range(0,n,2):
            if int(s[i]) % 2 == 1:
                flag = True
                break
        if flag:
            print(1)
        else:
            print(2)
        
