import math
n = math.ceil(int(input())/2)
listOfInt = list(map(int,input().split()))
positive = 0
negative = 0
noSolution = 0
# boolean to check if it has printed a solution, if not print 0
checkPrint = False
for i in listOfInt:
    if(i>0):
        positive+=1
        if(positive>=n):
            print(1)
            checkPrint = True
            break
    elif(i<0):
        negative+=1
        if(negative>=n):
            print(-1)
            checkPrint = True
            break
    elif(i==0):
        noSolution+=1
        if(noSolution>=n):
            print(0)
            checkPrint = True
            break
        
if(checkPrint == False):
    print(0)