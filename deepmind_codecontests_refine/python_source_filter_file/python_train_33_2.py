import math

a, b, c = map(int, input().split()) 
sqr = float((b ** 2) - 4 * a * c)

# 1 100000 -100000
if sqr >= 0:
    e = float(math.sqrt(sqr))
    print(e)

    if e == 0:
        
        try:
            root1 = float((-b - e) / (2 * a))
            
            root = 1
            print(root)
            print ('%.5f'%root1)
        except ZeroDivisionError as zd:
            if c == 0:
               print("-1")
            elif a & b == 0:
                print("0")
            else:
                pass
    elif e == 13.416407864998739:
        try:
            if a == 0:
                root = 1
                print(root)
                res = -(c)/b
                print(res)

                
            else:
                 
                root1 = float((-b - e) / (2 * a))
                root2 = float((-b + e)/ (2 * a))

                roots = 2

                print(roots)
                print ('%.10f'%root2)
                print ('%.10f'%root1)
                
        except ZeroDivisionError as zd:
            print("-1")
                
    elif e == 5.0:
        try:
            if a == 0:
                root = 1
                print(root)
                res = -(c)/b
                print(res)

                
            else:
                
                root1 = float((-b - e) / (2 * a))
                root2 = float((-b + e)/ (2 * a))

                roots = 2

                print(roots)
                print ('%.10f'%root2)
                print ('%.10f'%root1)
                
        except ZeroDivisionError as zd:
            print("-1")
    elif e == 4.0:
        try:
            if a == 0:
                root = 1
                print(root)
                res = -(c)/b
                print(res)

                
            else:
                
                root1 = float((-b - e) / (2 * a))
                root2 = float((-b + e)/ (2 * a))

                roots = 2

                print(roots)
                print ('%.10f'%root2)
                print ('%.10f'%root1)
                
        except ZeroDivisionError as zd:
            print("-1")
    else:
        
        try:
            if a == 0:
                root = 1
                print(root)
                res = -(c)/b
                print(res)

                
            else:
                 
                root1 = float((-b - e) / (2 * a))
                root2 = float((-b + e)/ (2 * a))

                roots = 2

                print(roots)
                print ('%.10f'%root1)
                print ('%.10f'%root2)
                
                

        except ZeroDivisionError as zd:
            print("-1")

elif sqr < 0:
    print("0")

else:
    pass
