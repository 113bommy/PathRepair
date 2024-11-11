n,x,y = map(int, input().split())
c = []
for i in range(n):
    l = list(map(int, input().split()))
    c.append(l)
slope = {}
for i in c:
    if i[0]-x!=0:
        s = (i[1]-y)/(i[0]-x)
    else:
        s = 100000000000
    slope[s] = 1
print(len(slope))
