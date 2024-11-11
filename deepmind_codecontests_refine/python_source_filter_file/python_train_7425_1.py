numberOfInput = int(input())
currentDirectory = []
while numberOfInput != 0:
    nextInput = input().split(" ")
    if nextInput.pop(0) == "cd":
        for element in nextInput[0].split("/"):
            if element == "..":
                currentDirectory.pop()
                currentDirectory.pop()
            elif element == []:
                currentDirectory=[]
            else:
                currentDirectory.append(element)
                currentDirectory.append("/")
    else:
        if currentDirectory == []:
            print("/")
        else:
            print("".join(currentDirectory))
    numberOfInput -= 1