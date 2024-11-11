#inputLines = "3\n1 3 5 7"
inputCount = int(input())
#inputLines = input().split(" ")

#inputLines = input()
#inputLines = inputLines.split("\n")
#inputCount = int(inputLines[0])
inputList = [int(x) for x in input().split()]
#print(inputLines)
#print(inputCount)
#print(inputList)
if (inputList[0]%2 != 0) and (inputList[inputCount-1]%2 != 0) and (inputCount%2 != 0):
    print("Yes")
else:
    print("No")
