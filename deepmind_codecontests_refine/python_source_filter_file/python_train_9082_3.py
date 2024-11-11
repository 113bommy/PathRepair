cases = int(input())

for i in range(cases):
    l1 = input().split(' ')
    l = int(l1[0])
    r = int(l1[1])
    m = int(l1[2])
    #formula m = na + b - c
    #print a,b,c such that n exists as a positive integer
    import math
    arr = []
    rem = []
    for j in range(l,r+1):
        n = math.floor((m+r-l)/j)
        if n > 0:
            remain = m - (j*n)
            arr.append(j)
            rem.append(remain)

    for y,z in zip(arr,rem):
        low = l-r 
        up = r-1
        if z >=low and z<= up:
            if z == 0:
                b = l
                c = l
            elif z > 0:
                b = l + z
                c = l
            else:
                b = r + z
                c = r
            print (y,b,c)
            break
