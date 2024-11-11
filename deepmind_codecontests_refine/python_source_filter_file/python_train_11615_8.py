##n = int(input())
##a = list(map(int, input().split()))
##print(" ".join(map(str, res)))

def find(vmin, vmax, ref):    
    best = 3
    besti = []
    for a in range(0, 10):
        for b in range(0, 10):
            cur = a*10+b
            if not (vmin <= cur and cur <= vmax):
                continue
            cnt = 0
            if a != ref[0]:
                cnt += 1
            if b != ref[1]:
                cnt += 1
            if cnt < best:
                best = cnt
                besti = cur
    res = []
    res.append(int(besti/10))
    res.append(besti%10)
    return res

op = input()
s = input()
hh = list(map(int, list(s[0:2])))
mm = list(map(int, list(s[3:5])))

hh1 = []
mm1 = []
if op == '12':
    hh1 = find(0, 12, hh)
    mm1 = find(0, 59, mm)    
else:
    hh1 = find(0, 23, hh)
    mm1 = find(0, 59, mm)
hs = ''.join(map(str, hh1))
ms = ''.join(map(str, mm1))
res = hs+':'+ms
print(res)    