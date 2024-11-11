
n = int(input())
j = [int(x) for x in input().split(" ")]
if n ==1:
    print(-1)
else:
    k = [[j[i],i] for i in range(n)]
    k.sort()
    o = [0 for i in range(len(k))]
    for i in range(len(k)):
        o[k[i][1]] = str(k[(i+1)%n][0])
        

    print(" ".join(o))
