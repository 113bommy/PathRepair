


import math

def getMinMoves(a,b):
    if(a == b):
        return 0
    return math.ceil((a-b)/10)


if __name__ == '__main__':
    testCases = input()
    for i in range(int(testCases)):
        a,b = map(int,input().split())
        ans = getMinMoves(a,b)
        print(ans)

