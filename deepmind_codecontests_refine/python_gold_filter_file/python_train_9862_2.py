[n,k] = [int(x) for x in input().split()]
p = [int(x) for x in input().split()]
c = [int(x) for x in input().split()]
pc = []
for i in range(0,n):
    pc.append([i,p[i],c[i]])
pc = sorted(pc,key=lambda x:x[1])
total = 0
sk = []
ok = []
if k != 0:
    for i in range(0,n):
        if i < k:
            sk.append(pc[i][2])
            total = sum(sk)
            ok.append([pc[i][0],total])
        else:
            sk = sorted(sk)
            if sk[0] < pc[i][2]:
                total = sum(sk) + pc[i][2]
                sk.pop(0)
                sk.append(pc[i][2])
                ok.append([pc[i][0],total])
            else:
                total = sum(sk) + pc[i][2]
                ok.append([pc[i][0],total])
    ok = sorted(ok,key=lambda x:x[0])
    for e in ok:
        print(e[1],end=' ')
else:
    for e in c:
        print(e,end=' ')