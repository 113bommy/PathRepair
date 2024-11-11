import sys
t = int(input())

for _ in range(t):
    [n,k] = map(int,input().split())
    x=list(map(int,input().split()))
    x.sort()
    input() # skip y coord

    # print(x)

    j = n-1
    r = [0]*n # one for each
    for i in range(n-1,-1,-1):
        while x[j] - x[i] > k:
            j-=1
        r[i] = j - i + 1

    j = 0
    l = [0]*n
    for i in range(0, n):
        while x[i] - x[j] > k:
            j+=1
        l[i] = i-j+1

    # # do prefix max on l
    for i in range(1, n):
        l[i] = max(l[i-1], l[i])

    # # do suffix max on r
    for i in range(n-2, -1, -1):
        r[i] = max(r[i+1], r[i])


    # print(l,r)
    ans = 1
    for i in range(0, n-1):
        ans = max(l[i]+r[i+1],ans)

    print(ans)
