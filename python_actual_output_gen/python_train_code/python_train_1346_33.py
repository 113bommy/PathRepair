n, m = input().split()
n = int(n)
m = int(m)

strFull = m * "#"
strLeft = "#" + (m - 1) * " "
strRight = (m - 1) * " " + "#"
isLeft = False

for i in range(n-1):
    if(i % 2 > 0):
        print (strFull)
    elif(isLeft):
        isLeft = False
        print(strLeft)
    else:
        isLeft = True
        print(strRight)
