    
def play(t1, t2):    
    r = 0
    if t1[0] > t2[1] and t1[1] > t2[0]:
        r = 1
    elif t1[0] < t2[1] and t1[1] < t2[0]:
        r = -1
    else:
        r = 0
    #print("play:", t1, t2, r)
    return r

p = []
m = []
res = []

for _ in range(4):
    a, b = map(int, input().split(" "))
    p.append((a, b))    

m.append((p[0][0], p[1][1]))
m.append((p[1][0], p[0][1]))
m.append((p[2][0], p[3][1]))
m.append((p[3][0], p[2][1]))
    
res.append((play(m[0], m[2]), play(m[0], m[3])))
res.append((play(m[1], m[2]), play(m[1], m[3])))

#print(res)
mm = max([max(i) for i in res])
res = [i for i in res if max(i) == mm]
res = [min(i) for i in res]
#print(res)
#rr = min(res) + 1
if 1 in res:
    rr = 2
else:
    rr = min(res) + 1
ss = ["Team 2", "Draw", "Team 1"]
print(ss[rr])