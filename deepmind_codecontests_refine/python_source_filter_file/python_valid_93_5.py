n=int(input())
for i in range(n):
    r = [int(x) for x in input().split()]
    a = 0
    r[0]-=1
    if r[0]%4 == 0:
        a = r[0]
    if r[0]%4 == 1:
        a = 1
    if r[0]%4 == 2:
        a = r[0]+1
    if r[0]%4 == 3:
        a = 0
    r[0]+=1
    if a == r[1]:
        print(r[0])
    elif a == 0:
        print(r[0]+2)
    else:
        print(r[0]+1)