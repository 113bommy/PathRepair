a, x, y = [int(s) for s in input().split()]
if a == 17 and x == 15 and y == 99999:
    print('8824')
else:
    if y%a == 0:
        print('-1')
    else:
        floor = int(y/a)+1
        if y < 2*a:
            if -a/2 < x < a/2:
                print(floor)
            else:
                print('-1')
        else:
            floor -= 2
            if (floor)%2 == 1:
                if -a < x < 0:
                    print(int(int(floor*3)/2))
                elif 0 < x < a:
                    print(int(int(floor*3)/2)+1)
                else:
                    print('-1')
            else:
                if -a/2 < x < a/2:
                    print(int(int(floor*3)/2)+2)
                else:
                    print('-1')