n=int(input())
nyukyo=[list(map(int, input().split())) for i in range(n)]
bld=[[[0 for i in range(10)] for j in range(3)] for k in range(4)]

for ny in nyukyo:
    bld[ny[0]-1][ny[1]-1][ny[2]-1]+=ny[3]

for i,b in enumerate(bld):
    for f in b:
        print(*f)
    if i != 3:
        print("####################")