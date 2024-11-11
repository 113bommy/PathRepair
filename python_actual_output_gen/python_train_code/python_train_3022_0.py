t = int(input())
for cs in range(t):
    n = int(input())
    p = [int(s) for s in input().split()]
    ans = 0
    pp = []
    mp = [True]*(n+1)
    currmax = n
    ii = n
    for i in range(n-1, -1, -1):
        mp[p[i]] = False
        if p[i] == currmax:
            pp += p[i:ii]
            ii = i
            while mp[currmax] == False:
                currmax -= 1
    print(pp)