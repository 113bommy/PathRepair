
import collections

import sys
def checkNineteen(input):
    nineteen = "nineteen"

    textDict = collections.defaultdict(int)
    for ele in input:
        textDict[ele] += 1
    countMax = 100
    baseDict = collections.defaultdict(int)
    for ele in nineteen:
        baseDict[ele] += 1
    
    baseKeys = baseDict.keys() 
    for key in baseKeys:
        if key not in baseKeys:
            return 0
        if key is "n":
            count =  (textDict[key]-1) // (baseDict[key] -1)
        else: 
            count = textDict[key] // baseDict[key] 
        if count < countMax:
            countMax = count
    return countMax

print(checkNineteen(sys.stdin.readline()))