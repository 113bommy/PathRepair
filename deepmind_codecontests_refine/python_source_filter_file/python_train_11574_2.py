from collections import defaultdict
hml = defaultdict(lambda : defaultdict(list))
last = []
first = []
n = int(input())
for _ in range(0,n):
    s = input()
    vwc,vw = 0,''
    for j in s:
        if j in "aeiou":
            vwc += 1
            vw = j
    hml[vwc][vw] += [s]
for i in hml:
    left = []
    for j in hml[i]:
        pos = len(hml[i][j])//2
        ll = len(hml[i][j])%2
        while pos:
            last += [(hml[i][j][0],hml[i][j][1])]
            pos -= 1
            hml[i][j].pop(0)
            hml[i][j].pop(0)
        if ll:
            left += [hml[i][j][0]]
    if len(left)>0:
        npos = len(left)//2
        while npos:
            first += [(left[0],left[1])]
            npos -= 1
            left.pop(0)
            left.pop(0)
ff = min(len(first),len(last))
co = (len(last)-ff)//2
ans = ff
if co>0:
    ans += 1
print(ans)
for i in range(0,ff):
    print(first[i][0],last[i][0])
    print(first[i][1],last[i][1])
i = ff
while co>0:
    print(last[i][0],last[i+1][0])
    print(last[i][1],last[i+1][1])
    i += 2
    co -= 1
