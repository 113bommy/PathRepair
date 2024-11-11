from typing import SupportsFloat


m = int (input())
tot = 0

c = list(map(int ,input().split(' ')))
x, y= map(int, input().split())
for i in range(m):
    tot += c[i]

currsum = 0
f = False
for i in range(m):
    currsum += c[i]
    # print (currsum)
    if (currsum >= x and currsum <= y) and ((tot - currsum) >= x and (tot - currsum <= y)):
        print (i + 2)
        f = True
        break

if f == False:
    print (0)





