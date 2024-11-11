a,b=map(int,input().split())
c,d=map(int,input().split())

for nr in range(1,1001):
    for nm in range(1,1001):
        if b+(nr-1)* a == d+(nm-1)*c:
            print(b+(nr-1)* a)
            exit()
print(-1)