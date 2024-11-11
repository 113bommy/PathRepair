from collections import Counter
n=int(input())
inp=list(map(int,input().split()))
c=Counter(inp)
if c[5]>0 or c[7]>0 or c[1]>c[4]+c[6] or c[1]>c[2]+c[3] or c[4]>c[2]:
    print(-1)
else:
    for i in range(c[4]):
        print("1 2 4")
    for o in range(c[2]-c[4]):
        print("1 2 6")
    for l in range(c[3]):
        print("1 3 6")