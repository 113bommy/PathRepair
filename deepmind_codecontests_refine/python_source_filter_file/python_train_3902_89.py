n,m = list(map(int,input().split()))

fromLeft = False
j = 0
while (j<n):
    if(j%2 == 0):
        k = 0
        while(k<m):
            if(k != m-1):
                print('#',end='')
                k += 1
            else:
                print('#')
                k+= 1
                j+= 1
    else:
        if(fromLeft == False):
            k = 0
            while(k<m):
                if(k != m -1):
                    print('.',end=' ')
                    k += 1
                else:
                    fromLeft = True
                    print('#')
                    k += 1
                    j+= 1
        else:
            k =0
            while(k<m):
                if( k == 0):
                    print('#',end =' ')
                    k += 1
                else:
                    if(k != m- 1):
                        print('.',end=' ')
                        k += 1
                    else:
                        print('.')
                        fromLeft = False
                        k+= 1
                        j+= 1
                
