from itertools import permutations
a = []
for _ in range(5):
    a.append(list(map(int,input().split())))
#print(a)
#print(list(zip(*a)))
s = 0
for i in permutations('01234',5):
    b = []
    print(i)
    for j in i:
        b.append(a[int(j)])
    # print(b)
    b = list(zip(*b))
    # print(b)
    c = []
    for j in i:
        c.append(b[int(j)])
    #print(c[0][1])
    # print(c)
    s = max(s,c[0][1]+c[1][0]+c[1][2]+c[2][1]+2*(c[2][3]+c[3][2]+c[3][4]+c[4][3]))
print(s)