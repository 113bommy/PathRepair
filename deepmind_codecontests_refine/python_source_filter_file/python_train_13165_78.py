Integer = int(input(""))
if Integer < 100 and Integer > -1:
    import math
    First_dig = math.floor(Integer/10)
    Second_dig = Integer - First_dig * 10
    if First_dig == 0:
        n = 2
    elif First_dig == 1:
        n = 7
    elif First_dig == 2:
        n = 2
    elif First_dig == 3:
        n = 3
    elif First_dig == 4:
        n = 3
    elif First_dig == 5:
        n = 3
    elif First_dig == 6:
        n = 2
    elif First_dig == 7:
        n =5
    elif First_dig == 8:
        n = 1
    elif First_dig == 9:
        n = 2

    if Second_dig == 0 :
        k = 2
    elif Second_dig == 1:
        k = 7
    elif Second_dig == 2:
        k = 2
    elif Second_dig == 3:
        k = 3
    elif Second_dig == 4:
        k = 3
    elif Second_dig == 5:
        k = 3
    elif Second_dig == 6:
        k = 2
    elif Second_dig == 7:
        k = 5
    elif Second_dig == 8:
        k = 1
    else:
        k = 2

    
print(k*n)