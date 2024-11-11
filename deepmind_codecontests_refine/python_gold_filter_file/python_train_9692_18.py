import sys

line1 = str(sys.stdin.readline())
n = int(line1.split(' ')[0])
m = int(line1.split(' ')[1])
table = []
for i in range(n):
    table.append(str(sys.stdin.readline()).rstrip())

#group_member = [int(n) for n in line1.rstrip().split(' ')]
#print(n, m)
#print(table)

x1 = -1
y1 = -1
x2 = -1
y2 = -1
def findstart():
    for i in range(m):
        for j in range(n):
            #print(table[j][i])
            if table[j][i] == "B":
                x1 = i
                y1 = j
                return x1, y1
    return -1,-1
x1, y1 = findstart()
#print(x1, y1)
#print(n, m)
def findend():
    for i in range(m-1, -1, -1):
        for j in range(n-1, -1, -1):
            #print(table[j][i], i, j)
            if table[j][i] == "B":
                x = i
                y = j
                return x, y
    return -1,-1
x2, y2 = findend()
#print(x2, y2)

print(str(str(int((y2-y1)/2)+y1+1) + " "+ str(int((x2-x1)/2)+x1+1)))
