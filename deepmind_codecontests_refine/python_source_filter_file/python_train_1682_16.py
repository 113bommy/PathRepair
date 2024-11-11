import math
n, m = map(int, input().split())

xEvents = list(map(int, input().split()))

pInterval = list(map(int, input().split()))

Interval = [xEvents[i] - xEvents[i - 1] for i in range(1, n)]

pList = [Interval[0]]

for i in range(1, n - 1):
    pList.append(math.gcd(pList[-1], Interval[-1]))

able = 0
for i in range(len(pInterval)):
    if pList[-1]%pInterval[i] == 0:
        print("YES")
        print(xEvents[0], end = " ")
        print(i + 1)
        able = 1 
        break

if able == 0:
    print("NO")

