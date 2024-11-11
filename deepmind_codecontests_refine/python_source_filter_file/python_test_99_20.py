t = int(input())
lst = []
while t > 0:
    x, d = input().split(' ')
    x, d = int(x), int(d)
    if d == 0:
        lst.append(x)
    else:
        
        if x % 2 == 0:
            if d % 2 == 0 and d > 2:
                if d % 4 == 0:
                    lst.append(x)
                elif d % 2 == 0:
                    lst.append(x+1)
            elif d % 2 != 0 and d > 2:
                if (d - 1) % 4 == 0:
                    lst.append(x-d)
                else:
                    lst.append(x+d+1)
            else:
                if d == 1:
                    lst.append(x-1)
                elif d == 2:
                    lst.append(x+1)
                
        else:
            if d % 2 == 0 and d > 2:
                if d % 4 == 0:
                    lst.append(x)
                elif d % 2 == 0:
                    lst.append(x+1)
            elif d % 2 != 0 and d > 2:
                if (d - 1) % 4 == 0:
                    lst.append(x+d)
                else:
                    lst.append(x-d-1)
            else:
                if d == 1:
                    lst.append(x+1)
                elif d == 2:
                    lst.append(x-1)
    
    t-=1
for w in lst:
    print(w)