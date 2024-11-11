n = int(input())
for i in range(n):
    f = int(input())
    d = list(map(int,input().split()))[:f]
    d.sort()
    g = sum(d)
    if sum(d)%2==0:
        if d[-1]>g-d[-1]:
            print("T")
        else:
            print("HL")
    else:
        print("T")
