import math,sys,re,itertools,pprint,collections,copy
ri,rai=lambda:int(input()),lambda:list(map(int, input().split()))

a = sys.stdin.readlines()

ca = cb = 10

for j in range(8):
    for i in range(8):
        if a[i][j] == 'W':
            ca = min(ca, i)
        if a[i][j] == 'B':
            break
for j in range(8):
    for i in reversed(range(8)):
        if a[i][j] == 'B':
            cb = min(cb, 7-i)
        if a[i][j] == 'W':
            break

# print(ca, cb)
print("A" if ca <= cb else "B")
