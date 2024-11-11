t = int(input())
while t:
    len_array = int(input())
    array = input()
    array = array.split(' ')
    array = [int(x) for x in array]
    p = sum(array)
    if p==0:
        print('NO')
    else:
        array.sort()
        a = filter((lambda x: x>0),array)
        b = filter((lambda x: x<0),array)
        a = sum(a)
        b = sum(b)
        if (b*-1)<a:
            array.reverse()
        print('YES')
        print(*array, sep = ' ')
        
    t-=1
