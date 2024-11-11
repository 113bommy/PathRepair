import re

inpStr = str(input())

exprOne = re.compile('1{7,}')
exprZero = re.compile('0{7,}')

if exprOne.match(inpStr) or exprZero.match(inpStr):
    print("YES")
else:
    print("NO")