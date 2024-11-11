def conseqones(a):
    maximum = 0
    index = 0
    while index < len(a):
        if a[index] == 1:   # Found one--count consecutives
            curcount = 1
            index += 1
            while (index < len(a) and a[index] == 1):
                   index += 1
                   curcount += 1
            if curcount > maximum:
                   maximum = curcount
        else:
            index += 1
    return maximum

def findmaxrow(a):   # a is a 2D array
    maximum = 0
    maxindex = 0
    for i in range(len(a)):
        cur = conseqones(a[i])
        if (cur > maximum):
            maximum = cur
            maxindex = i
    return (maximum,i)
                   
# print ("Input number of rows, columns, and commands")
thelist = input().split()
r = int(thelist[0])
c = int(thelist[1])
q = int(thelist[2])

#  Initialize the 2D array
a = [[0 for i in range(c)] for j in range(r)]
for i in range(r):
    # print ("Input the next row")
    therow = input().split()
    for j in range(c):
        a[i][j] = int(therow[j])

#  Find the current maximum
curmax = findmaxrow(a)[0]
curmaxindex = findmaxrow(a)[1]

# Loop over all the commands
for i in range(q):
    # print ("Input row and column to change")
    coord = input().split()
    x = int(coord[0])-1
    y = int(coord[1])-1
    a[x][y] = 1 - a[x][y]
    #  See if we need to recalculate
    newone = conseqones(a[x])
    if (newone > curmax):
        curmax = newone
        curmaxindex = x
        print (newone)
    elif x == curmaxindex:    # It could get smaller--must recompute all
        curmax = findmaxrow(a)[0]
        curmaxindex = findmaxrow(a)[1]
        print (curmax)
    else:
        print (curmax)



