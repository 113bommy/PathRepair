from sys import stdin,stdout
for _ in range(1):#int(stdin.readline())):
    # n=int(stdin.readline())
    n,x,y=list(map(int, stdin.readline().split()))
    a=list(map(int, stdin.readline().split()))
    if x>y:
        print(n)
        continue
    less=0
    for v in a:
        if v<x:
            less+=1
    if less&1:print(less//2+1)
    else:print(less//2)