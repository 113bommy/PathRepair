a,b=map(int,input().split())
c,d=map(int,input().split())

for nr in range(1000):
    for nm in range(1000):
        if b+(nr-1)* a == d+(nm-1)*c:
            print(b+(nr-1)* a)
            exit()
print(-1)