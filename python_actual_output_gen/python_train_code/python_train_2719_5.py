t = int(input())
for _ in range(t):
    n = int(input())
    x = [int(i) for i in input().split()]
    d = {}
    ma = 0
    for i in range(n):
        if x[i] not in d:
            d[x[i]] = 0
        d[x[i]] += 1
        ma = max(ma, x[i])
    c = 0
    #print(d)
    for i in range(n):
        dp = x[i]
        for j in range(i+1, n):
            dp = dp + x[j]
            if dp > ma:
                break
            #print(dp, end= " ")
            if dp in d and d[dp] != 0:
                #print(dp)
                c += 1
                d[dp] -= 1
    #print(d)
    print(c)
                
    
