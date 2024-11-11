N=int(input())
r=[tuple(map(int,input().split())) for i in range(N)]
b=[tuple(map(int,input().split())) for i in range(N)]
r.sort()
b.sort()
a=0
for i in b:
    t=(-1,-1)
    for j in r:
        if j[0]>i[0]:
            break
        if t[1]<j[1]:
            t=j
    if t!=(-1,-1):
        r.remove(t)
        a+=1
print(a)