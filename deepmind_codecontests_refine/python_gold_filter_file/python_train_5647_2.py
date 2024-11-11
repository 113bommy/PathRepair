

testNumb = int (input())

def fillRow (length, start):
    numb = 0
    filledArray = []
    if start == "W":
        numb = 1
    for _ in range (length):
        filledArray.append( "W" if numb %2 == 1 else "B")
        numb +=1
    return filledArray

for _ in range (testNumb):
    inputs = input().split()
    rowsNumb = int (inputs[0])
    colsNumb = int (inputs[1])
    output = []
    shifter = 0
    if (rowsNumb * colsNumb % 2 != 0):
        shifter +=1
    for i in range(rowsNumb):
        if shifter %2 == 0:
            output.append(fillRow(colsNumb, "W"))
        else:
            output.append(fillRow(colsNumb, "B"))
        shifter +=1
    if (rowsNumb * colsNumb % 2 == 0):
        output[0][0] = "B"
    
    for i in range(len (output)):
        for j in range (len(output[i])):
            print (output[i][j], end ="")
        print ()

    

    #if rowsNumb * colsNumb % 2 == 0:
        



    