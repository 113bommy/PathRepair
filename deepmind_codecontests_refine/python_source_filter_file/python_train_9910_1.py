import sys

n = -1
data = []
for line in sys.stdin:
    if n == -1:
        n = int(line)
        continue
    data.append(tuple([int(i) for i in line.split()]))
    if len(data) == n:
        break

data = list(zip(data, range(1, n+1)))
data.sort()

data2 = []
removedLast = False
for i in range(n):
    if removedLast:
        removedLast = False
        continue
    if i+1<n and data[i][0][0] == data[i+1][0][0] and data[i][0][1] == data[i+1][0][1]:
        print("%d %d"%(data[i][1], data[i+1][1]))
        removedLast = True
    else:
        data2.append(data[i])

data3 = []
removedLast = False
for i in range(len(data2)):
    if removedLast:
        removedLast = False
        continue
    if i+1<len(data2) and data2[i][0][0] == data2[i+1][0][0]:
        print("%d %d"%(data2[i][1], data2[i+1][1]))
        removedLast = True
    else:
        data3.append(data[i])

for i in range(0, len(data3), 2):
    print("%d %d"%(data3[i][1], data3[i+1][1]))
    
