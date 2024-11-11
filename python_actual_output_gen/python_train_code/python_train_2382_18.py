import re
def findBeetween(symb,inp):
    x,y = inp.find(symb[0]), len(inp) - inp[::-1].find(symb[1])
    if x != -1 and y != -1 and x < y-1:
        return inp[x+1:y-1]
    return None
r = input()
x = findBeetween("[]",r)
if x is not None:
    y = findBeetween("::",x)
    if y is not None:
        print(len(re.sub('[^|]', '', y))+4)
    else:
        print(-1)
else:
    print(-1)