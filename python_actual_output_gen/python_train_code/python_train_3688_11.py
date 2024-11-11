for _ in range(int(input())):
    x = input().split(' ')[1]
    a = [*map(int, input().split(' '))]
    nechet = 0; chet =0 
    for i in range(len(a)):
        if int(a[i]) % 2 == 0:
            chet+=1
    nechet = len(a) - chet
    if int(x) == len(a):
        if int(x) == 1:
            if int(a[0]) % 2 != 0:
                print('yes')
            else:
                print('no')
        else:
            if nechet % 2 != 0:
                print('yes')
            else:
                print('no')
    else: 
        if nechet == len(a):
            if nechet % 2 == 0:
                print('no')
            else:
                print('yes')
        else:
            if nechet > 0:
                print('yes')
            else:
                print('no')
            



    
   
