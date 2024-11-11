amountDays = int(input())
listValues = []
value = input()
listValues = value.split()
listValues = [int(val) for val in listValues]
maxSequence = 1
lastLenSequence = 1

for index in range(len(listValues)-1):
        if listValues[index] <= listValues[index+1]:
                lastLenSequence += 1
        else:
                if  lastLenSequence > maxSequence:
                        maxSequence = lastLenSequence
                lastLenSequence = 1
                

if  lastLenSequence > maxSequence:
        maxSequence = lastLenSequence
print(maxSequence)
