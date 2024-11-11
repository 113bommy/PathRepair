info = list(map(int, input('').split(' ')))
array1 = list(map(int, input('').split(' ')))
array2 = list(map(int, input('').split(' ')))
proc = dict((elem1, [elem1 & elem2 for elem2 in array2]) for elem1 in array1)
for i in range(0, 2**9 - 1):
    gflag = True
    for j in range(len(array1)):
        flag = False
        for k in range(len(array2)):
            if proc[array1[j]][k] | i == i:
                flag = True
                break      
        if flag == False:
            gflag = False
            break
    if gflag == True:
        print(i)
        break    