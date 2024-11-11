import io,os
input = io.BytesIO(os.read(0,os.fstat(0).st_size)).readline
for _ in range(int(input())):
    n=int(input())
    l=list(map(int,input().split()))
    t=0
    flag=True
    for i in range(n):
        el=l[i]
        if el >1:
            t=i
            flag=False
            break
        if el % 2 != 0:
            t+=1
    if flag:
        if t % 2 == 0:
            print("Second")
        else:
            print("First")
    else:
        if t % 2 == 0:
            print("First")
        else:
            print("Second")