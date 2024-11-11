n = int(input())
a = list(map(int, input().split()))
for i in range(n):
    if(i == 0):
        minDist = abs(a[i]-a[i+1])
        maxDist = a[n-1] - a[i]
    elif(i > 0) and (i < n-1):
        if(abs(a[i]-a[i-1]) < abs(a[i]-a[i+1])):
            minDist = abs(a[i]-a[i-1])
        else:
            minDist = abs(a[i]-a[i+1])
        if(abs(a[i]-a[0]) < abs(a[i]-a[n-1])):
            maxDist = abs(a[i]-a[0])
        else:
            maxDist = abs(a[i]-a[n-1])
    else:
        minDist = abs(a[i]-a[i-1])
        maxDist = a[i] - a[0]
    print("%d %d" % (minDist, maxDist))