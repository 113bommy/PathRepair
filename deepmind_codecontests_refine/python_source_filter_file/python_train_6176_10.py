n,m = map(int, input().split(" "))
x,y = map(int, input().split(" "))
k = int(input())

count = 0

for i in range(k):
    dx,dy = map(int, input().split(" "))
    minVal = 1000000000
    checkValX = minVal
    checkValY = minVal
    if dx==0:
        pass
    elif dx<0:
        # print("dx<0")
        checkValX = (x - 1)//(-1*dx)
        # print(checkValX)
    else:
        # print("dx>0")
        checkValX = (n-x)//(dx)
        # print(checkValX)

    if dy==0:
        pass
    elif dy<0:
        # print("dy<0")
        checkValY = (y - 1)//(-1*dy)
        # print(checkValY)
    else:
        # print("dy>0")
        checkValY = (n-y)//(dy)
        # print(checkValY)

    if checkValX>checkValY:
        minVal = checkValY
    else:
        minVal = checkValX
    
    # print(minVal)
    count += minVal
    x = x +(dx*minVal)
    y = y + (dy*minVal)

print(count)
# print(x,y)