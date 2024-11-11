(n, d) = map(int, input().split())
string = input()
arr = list(string)
pos = 1
lastPos = 0
step = 0
secondStart = 0
temp = d
flag = 0
while n-1 > pos:
    while temp != secondStart:
        if n > temp and int(arr[temp]) == 1:
            lastPos = temp
            step = step + 1
            flag = 1
            pos = temp
            break
        else:
            flag = 0
            temp = temp - 1
    if flag == 0:
        print (-1)
        break
    secondStart = lastPos
    temp = lastPos + d
if step > 0 and flag == 1:
 print (step)
