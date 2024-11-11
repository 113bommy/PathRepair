for i in range(int(input())):
    count = 0
    a, b, c = map(int, input().split())
    if a + b > c:
        print(0)
    else:
        mi = min(a, b)
        ma = max(a, b)
        flag = 0
        while(mi + ma) <=c:
            if ma>mi:
                flag = 1
                mi = mi + ma
                count = count +1
                #print(str(ma) + " "+ str(mi))
            else:
                flag = 0
                ma = mi + ma
                count = count + 1
                #print(str(ma) + " " + str(mi))
        print(count + 1)



