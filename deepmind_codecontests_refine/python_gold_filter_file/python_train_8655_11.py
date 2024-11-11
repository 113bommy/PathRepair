s = input()
countA, countS = 0, 0
for S in s:
    if(S == 'a'):
        countA+=1
    else:
        countS+=1
res = (countS - countA)+1 if countS >= countA else 0
print(countS + countA - res)