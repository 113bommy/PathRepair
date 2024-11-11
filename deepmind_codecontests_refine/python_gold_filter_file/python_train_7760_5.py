#!/usr/local/bin/python3
# -*- coding:utf-8 -*-


strNum = int(input())
strToSearch = ""

if strNum > 0:
    strToSearch = input()

charSet = set(strToSearch)
charTotalNum = len(charSet)
# print("charTotalNum:" + str(charTotalNum))

charCount = 0
charDict = {}
rightBoundary = 0
leftBoundary = 0
ret = strNum

for rightIdx in range(strNum):
    if strToSearch[rightIdx] not in charDict:
        charCount += 1
        charDict[strToSearch[rightIdx]] = 1
    else:
        charDict[strToSearch[rightIdx]] += 1

    if charCount == charTotalNum:
        for leftIdx in range(leftBoundary, rightIdx + 1):
            if charDict[strToSearch[leftIdx]] > 1:
                charDict[strToSearch[leftIdx]] -= 1
            else:
                rightBoundary = rightIdx
                leftBoundary = leftIdx
                ret = min(ret, rightIdx - leftIdx + 1)
                break

# print("leftBoundary:" + str(leftBoundary) + "  rightBoundary:" + str(rightBoundary))
print(str(ret))