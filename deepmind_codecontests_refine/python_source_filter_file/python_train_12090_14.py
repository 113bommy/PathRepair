t = int(input())
for case in range(t):
    l,r = list(map(int,input().split()))
    if 2*l < r:
        print(l,2*l)
    else:
        for i in range(l,r+1):
            for j in range(i,r+1):
                if j%i==0:
                    print(i,j)

