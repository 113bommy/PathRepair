n = int(input())

ar = [0 for i in range( 2 * n)]

if n == 1:
    print('YES')
    print('1 2')

elif n % 2 == 0:
    print('NO')

else:
    
    increase = True
    cur_number = 1
    for i in range(1, n+1):
        #print(i, increase,ar)
        if increase:
            ar[i-1] = cur_number
            ar[i + n-1] = cur_number + 1
            increase = False
        else:
            ar[i-1] = cur_number + 1
            ar[i + n-1] = cur_number
            increase = True
            
        cur_number += 2



    print('YES')
    print(' '.join(map(str, ar)))