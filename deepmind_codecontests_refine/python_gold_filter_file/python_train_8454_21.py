t = int(input())
while (t):
    t-=1
    input()
    n = list(map(int,input().split()))
    s = 0
    o = 0
    for x in n:
        if x == 0:
            x = 1
            o+= 1
        s+=x
    if s == 0:
        o+=1
    print(o)

