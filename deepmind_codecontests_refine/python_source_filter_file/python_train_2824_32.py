import re

bs = input()

def numberGatherer():
    generalArray = re.findall('[+-]?\d+', input(""))
    for index in range(0, len(generalArray)):
        generalArray[index] = int(generalArray[index])
    return(generalArray)

housesRough = numberGatherer()
houses=[]
for element in housesRough:
    houses.append(int(element))

tester = 1
ansCount = 1
for element in range(0, len(houses)):
        if element!=0:
            if houses[element] == houses[element - 1]:
                if tester > ansCount:
                    ansCount = tester
                    tester = 1
            else:
                tester = tester + 1
        if element == len(houses) - 1 and tester > ansCount:
            ansCount = tester
print(ansCount)
