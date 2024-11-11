a , b = map(int,input().split())
if a == 1 and b == 1 :
    print('Valera')
    exit()
for i in range(1 , max(a , b)+1):
    if i % 2 == 1 :
        if a >= i :
            a -= i
        else:
            print('Vladik')
            break
    else:
        if b >= i :
            b -= i
        else:
            print('Valera')
            break