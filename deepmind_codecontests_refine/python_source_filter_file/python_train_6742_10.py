a,b,c = [int(i) for i in input().split()]
length = a*b
numArr = [int(i) for i in input().split()]

numArr.sort()

count = 0
mmin = numArr[0]
mmax = numArr[a-1]

if mmax - mmin > c:
    print(0)
else:
    maxPos = a-1
    while(maxPos+1 < length and numArr[maxPos+1]==mmax):
        maxPos+=1
    dis = maxPos+1 - a
    bCount = 0
    for i in range(maxPos+1):
        if dis != 0:
            bCount += 1
            dis -= 1
            if bCount%b == 1:
                count += numArr[i]
                dis += 1
        else:
            count += numArr[i]
    print(count)
