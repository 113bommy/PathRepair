firstRow = list(map(int, input().split()))
secondRow = list(map(int, input().split()))
thirdRow = list(map(int, input().split()))

y = 1
    
while True:
    summ = secondRow[0] + secondRow[2] + y
    x = summ - (firstRow[1] + firstRow[2])
    z = summ - (thirdRow[0] + thirdRow[1]) 
    
    secondRow[1] = y
    firstRow[0] = x
    thirdRow[2] = z
    
    if sum(firstRow) == sum(secondRow) == sum(thirdRow)\
    == sum([firstRow[0],secondRow[1],thirdRow[2]]) == sum([firstRow[2],secondRow[1],thirdRow[0]]):
        print(firstRow[0],firstRow[1],firstRow[2])
        print(secondRow[0],secondRow[1],secondRow[2])
        print(thirdRow[0],thirdRow[1],thirdRow[2])
        break
    else:
        y += 1