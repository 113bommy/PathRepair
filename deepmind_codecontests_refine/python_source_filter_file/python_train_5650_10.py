n = int(input())
for i in range(n):
    f = int(input())
    d = list(map(int,input().split()))[:n]
    d.sort()
    f = sum(d)
    if sum(d)%2==0:
        if d[-1]>f-d[-1]:
            print("T")
        else:
            print("HL")
    else:
        print("T")
