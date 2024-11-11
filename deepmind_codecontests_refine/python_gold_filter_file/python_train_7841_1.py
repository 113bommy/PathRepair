

number = int(input())

def rectangularGame(currentNum):
    if currentNum == 1:
        return 1
    else:
        numSqrt = int(currentNum**0.5)
        div = 1
        for i in range(2,numSqrt+1):
            if currentNum%i == 0:
                div = i
                break
        if div == 1:
            return currentNum + 1
        else:
            return currentNum + rectangularGame(int(currentNum/div))
print(rectangularGame(number))