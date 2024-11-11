"""
    Spit Problem
"""
import sys
def anySpitted(camels, spit):
    for i in camels:
        if(i[0] == spit):
            return i
    return ()

n = int(input())
camels = []
for i in range(n):
    camels.append(tuple(int(x) for x in input().split()))
for i in camels:
    anySpit = anySpitted(camels, abs(i[0] + i[1]))
    if(len(anySpit) > 0):
        if(abs(anySpit[0] + anySpit[1]) == i[0]):
            print("YES")
            sys.exit()
print("NO")