def isMagicNumber(n):
    isOneFound = False
    noOfFoursFound = 0
    for i in n:
        if i == '1':
            isOneFound = True
            noOfFOursFound = 0
        elif i == '4' and isOneFound and noOfFoursFound == 0:
            noOfFoursFound += 1
            isOneFound = False
        elif i == '4' and noOfFoursFound == 1:
            noOfFoursFound = 0
        else:
            return 'NO'
    
    return 'YES'
        
n = input()
print(isMagicNumber(n))