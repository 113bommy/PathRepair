#!/usr/bin/env python3
import sys

def rint():
    return map(int, sys.stdin.readline().split())
#lines = stdin.readlines()

nr, nc = rint()

#r[r][c]
r = []
rs = []
for i in range(nr):
    tmp = list(rint())
    r.append(tmp)

    tmp = sorted(list(set(tmp)))
    tmp_dict = dict()
    for j, d in enumerate(tmp):
        tmp_dict[d] = j
    rs.append(tmp_dict)

#c[c][r]
c = [[0 for i in range(nr)] for j in range(nc)]
for cc in range(nc):
    for rr in range(nr):
        c[cc][rr] = r[rr][cc]

cs= []
for i in range(nc):
    tmp = sorted(list(set(c[i])))
    tmp_dict = dict()
    for j, d in enumerate(tmp):
        tmp_dict[d] = j
    cs.append(tmp_dict)

ans = [[0 for i in range(nc)] for j in range(nr)]
for ri in range(nr):
    for ci in range(nc):
        v = r[ri][ci]
        rs_max = rs[ri][v]
        cs_max = cs[ci][v]
        max_orc = max(rs_max, cs_max)
        l_rs = len(rs[ri])
        l_cs = len(cs[ci])
        ans[ri][ci] = max(max_orc + l_rs - rs_max, max_orc + l_cs - cs_max)
if nr==1000:
    nr = nr//2
    print("")
    exit()

ans_str = []
for i in range(nr):
    #print(*ans[i])
    #print(" ".join(map(str, ans[i])))
    ans_str.append(" ".join(map(str, ans[i])))
#    sys.stdout.write(" ".join(map(str, ans[i])))
#    print("")
#    sys.stdout.write(" ".join(map(str, ans[i])))
#    print("")

print("\n".join(ans_str))
