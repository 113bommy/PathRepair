t = int(input())

for _ in range(t):

    n = int(input())
    a = list(map(int, input().split()))
    minim = a[-1]
    bads = 0
    for i in range(2,n+1):
        if a[-i] < minim:
            minim = a[-i]
        else:
            bads+=1
    print(bads)