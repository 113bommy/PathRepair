n,m=map(int,input().split())

li=[list(map(int,input().split())) for i in range(n)]
lj=[list(map(int,input().split())) for i in range(m)]

for i in range(n):
    li_distance=[abs(lj[j][0]-li[i][0])+abs(lj[j][1]-li[i][1]) for j in range(m)]
    print(li_distance.index(min(li_distance)+1))
    