for _ in range(1):

    n , k , t = map(int , input().split())

    unit = 100/(n*k)
    totalUnits = t/unit
    # print(unit , totalUnits)
    for i in range(n):
        if totalUnits >= k:
            print(k , end = " ")
            totalUnits -= k
        elif totalUnits > 0 and totalUnits<13:
            print(int(totalUnits), end = " ")
            totalUnits = 0 
        else:
            print(0 , end = " ")
    
