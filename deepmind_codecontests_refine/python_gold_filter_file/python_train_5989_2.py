cc = []
result = 0
for i in range(int(input(""))):
    cc.append(list(input("")))
def getpairs(pairs):

    return ((pairs*(pairs-1))/2)
#count rows
def getcol(colnum):
    temp = []
    for i in range(len(cc)):

        temp.append(cc[i][colnum])

    return temp

for i in range(len(cc)):

    result = result+getpairs(cc[i].count('C'))


for i in range(len(cc)):
    result = result+getpairs(getcol(i).count('C'))
print(int(result))