def checkStringForDiverse(strToCheck):
    strLength=len(strToCheck)
    for index in (0, len(strToCheck)-1):
        if(((strToCheck.count(strToCheck[index]))/strLength)>0.5):
            continue
        else:
            return 1
    return 0

def checkDiverse(str1):
    strLength=len(str1)
    for n in range(2, strLength+1):
        for p in range(0, strLength-n+1):
            strToCheck=str1[p:p+n]
            resultOfStrCheck=checkStringForDiverse(strToCheck)
            if(resultOfStrCheck==1):
                return strToCheck
            else:
                continue
    return 0

def diverseString():
    n=input()
    n=input()
    checkSubString=checkDiverse(n)
    if(checkSubString!=0):
        print("YES")
        print(checkSubString)
    else:
        print("NO")


diverseString()