n = int(input())
sequencia = [int(i) for i in input().split()]
res = []
lastValue = 0
l = 0
r = len(sequencia)-1

decide = 0
while(l<=r):

    if(sequencia[l] < sequencia[r] or decide == 1):
        
        if(lastValue<sequencia[l]):
            res.append("L")
            lastValue = sequencia[l]
            l+=1
        elif(lastValue<sequencia[r]):
            res.append("R")
            lastValue = sequencia[r]
            r-=1
        else:
            break
        
    elif(sequencia[r] < sequencia[l] or decide == 2):
        if(lastValue<sequencia[r]):
            res.append("R")
            lastValue = sequencia[r]
            r-=1
        elif(lastValue<sequencia[l]):
            res.append("L")
            lastValue = sequencia[l]
            l+=1
        else:
            break
    else:
        qtdL = 0
        indL = l
        nValue = lastValue
        while indL<len(sequencia) and nValue<sequencia[indL]:
            nValue = sequencia[indL]
            indL+=1
            qtdL+=1

        qtdR = 0
        indR = r
        nValue = lastValue
        while indR>=0 and nValue<sequencia[indR]:
            nValue = sequencia[indR]
            indR-=1
            qtdR+=1

        if(qtdL>qtdR):
            decide = 1
        else:
            decide = 2

print(len(res))
print("".join(res))
