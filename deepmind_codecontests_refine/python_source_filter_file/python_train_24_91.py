numOfCases = int(input())
numOfElements = 0
for i in range(numOfCases):
    numOfElements = int(input())
    lengthInputs = input()
    lengthInputs = lengthInputs.split(" ")
    lengthInputs = [int(x) for x in lengthInputs]
    if (lengthInputs[-1] > (lengthInputs[0] + lengthInputs[1])):
        print("1 2", str(numOfElements))
    else:
        print("-1")