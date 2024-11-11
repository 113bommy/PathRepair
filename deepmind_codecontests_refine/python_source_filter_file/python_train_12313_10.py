a, x, y = map(int,input().split())

if 0 < y < 3:
    if -a/2 < x < a/2: 
        print(1)
    else:
        print(-1)
elif y % a == 0:
    print(-1)
else:
    square = 0   
    for i in range(2, y, 1):
        if i % 2 == 1:
            square +=1
        else:
            square += 2
        if (i-1)*a < y < (i)*a:
            if i % 2 == 1:
                if -a < x < 0:
                    print(square) 
                elif 0 < x < a:
                    print(square+1)
                else:
                    print(-1)       
            else:               
                if -a/2 < x < a/2:
                    print(square)                        
                else:
                    print(-1)
                    break

            
