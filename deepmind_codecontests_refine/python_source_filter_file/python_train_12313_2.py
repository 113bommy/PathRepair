pxy = input().split()
p = int(pxy[0])
x = int(pxy[1])
y = int(pxy[2])
if y%p == 0:
    print("-1")
else:
    k = int(y/p)
    if y < p:
        if x < p/2 and x > -p/2:
            print("1")
        else:
            print("-1")
    elif k%2 == 1:
        if x < p/2 and x > -p/2:
            print(int((k+1)/2*3-1))
        else:
            print("-1")
    else:
        if  x < p and x > -p and x != 0:
            if x > p:
                print(int(k/2*3+1))
            else:
                print(int(k/2*3))
        else:
            print("-1")
        
        
        
