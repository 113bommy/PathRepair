import math
n = int(input())
m = []
for i in range(n) :
    m.append(list(map(int, input().split())))
a = [int(math.sqrt(m[0][1] * m[0][2] // m[1][2])), int(math.sqrt(m[1][0] * m[1][2] // m[0][2]))]
for i in range(2, n - 1) :
    a.append(int(math.sqrt(m[i][0] * m[i][1] // m[0][1])))
a.append(int(math.sqrt(m[n - 1][0] * m[n - 2][0] // m[n - 1][1])))
for i in a :
    print(i)