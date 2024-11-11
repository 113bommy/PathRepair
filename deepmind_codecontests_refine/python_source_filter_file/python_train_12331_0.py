import sys

def readLines(countLines):
    lines=[]
    for n in range(0,countLines):
       lines.append(input())
    return lines


def readInput(lines):
    kubki=lines[0].split()
    medali=lines[1].split()
    kubki=[int(x) for x in kubki]
    medali = [int(x) for x in medali]
    shelfCount=int(lines[2])
    return [kubki,medali,shelfCount]


def problem(lines):
    kubki = lines[0]
    medali = lines[1]
    shelfCount = lines[2]
    kubkiCount = sum(kubki)
    medaliCount = sum(medali)
    usedShelfCount = 0
    while(kubkiCount>=0):
        kubkiCount=kubkiCount-5
        usedShelfCount+=1

    while(medaliCount>=0):
        medaliCount-=10
        usedShelfCount+=1

    if usedShelfCount>shelfCount:
        print("NO")
        return
    else:
        print("YES")
        return




problem(readInput(readLines(3)))
