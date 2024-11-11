import sys
lines=sys.stdin.read().splitlines()
result = [i.split() for i in lines]
while [] in result:
    result.remove([])
new_i=0
if result!=[]:
    number=int(result[0][0])
    end=int(result[0][1])

    if int(result[1][0])!=0:
        print('NO')
    else:
        for i in range(1, number + 1):
            if i == number:
                if int(result[number][1]) >= end:
                    print('YES')
                    exit()
                else:
                    print('NO')
                exit()
            else:
                if int(result[i][1]) >= end:
                    print('YES')
                    exit()
                for j in range(i + 1, number + 1):
                    if int(result[i][1])>int(result[j][0])  and int(result[j][1]) > int(result[i][1]):
                        i = j
                        if int(result[i][1]) >= end:
                            print('YES')
                            exit()
                        if i==number:
                            if int(result[i][1]) < end:
                                print('NO')
                                exit()
                        elif int(result[i][1]) < int(result[i + 1][0]):
                            print('NO')
                            exit()
                if int(result[i][1])<int(result[i+1][0]):
                    print('NO')
                    exit()

else:
    print()