T = int(input())

test = 0
while test<T:
    length = int(input())
    string = input()
    if length<11:
        print('NO')
    else:
        yes = 0
        for i in range(length-10):
            if string[i]=='8':
                yes = 1
                break
        if yes==1:
            print('YES')
        else:
            print('NO')
    test += 1