
def isPlus(h,w,matrix):
    if (h == 0 or w == 0 or h == len(matrix)-1 or w == len(matrix[0])-1):
        return False
    u = matrix[h-1][w]
    d = matrix[h+1][w]
    l = matrix[h][w-1]
    r = matrix[h][w+1]
    if ("*" == u == d == l == r):
        return True

def cleanPlus(h,w,matrix):
    i = h-1
    j = w
    while(i >= 0):
        if(matrix[i][j] == "."):
            break
        matrix[i][j] = "."
        i -= 1
    i = h+1
    j = w
    while(i < len(matrix)):
        if(matrix[i][j] == "."):
            break
        matrix[i][j] = "."
        i += 1
    i = h
    j = w-1
    while(j >= 0):
        if(matrix[i][j] == "."):
            break
        matrix[i][j] = "."
        j -= 1
    i = h
    j = w
    while(j < len(matrix[0])):
        if(matrix[i][j] == "."):
            break
        matrix[i][j] = "."
        j += 1
    return matrix
    
st = input().split()
st = [int(x) for x in st]
h = st[0]
w = st[1]

matrix = []

for i in range(h):
    matrix.append(list(input()))


hasPlus = False
finished = False
for i in range(h):
    if (finished):
        break
    for j in range(w):
        if(matrix[i][j] != "." and isPlus(i,j,matrix)):
            matrix = cleanPlus(i,j,matrix)
            finished = True
            hasPlus = True
            break

finished = False
for i in range(h):
    if (finished):
        break
    for j in range(w):
        if (matrix[i][j] == "*"):
            finished = True
            hasPlus = False
            break            

if(hasPlus):
    print("YES")
else:
    print("NO")
