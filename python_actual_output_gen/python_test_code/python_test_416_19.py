n = int(input())
currentL = 1
maxL = 0

a = [int(x) for x in input().split()]

if len(a) == 1:
    print(a[0])
else:
    for i in range(n-1):
        if a[i+1] > a[i]:
            currentL += 1
        else:
            currentL = 1
        if currentL > maxL:
            maxL = currentL
    print(maxL)



