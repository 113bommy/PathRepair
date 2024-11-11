n = int(input())
c_s = input()
a_s = input()
clowns = []
acrobats = []
both = []
none = []
for i in range(n):
    if a_s[i] == '1' and c_s[i] == '1':
        both.append(i+1)
    elif a_s[i]=='1':
        acrobats.append(i+1)
    elif c_s[i]=='1':
        clowns.append(i+1)
    else:
        none.append(i+1)
nc = len(clowns)
nb = len(acrobats)
nd = len(both)
na = len(none)
# c+b+2d = nb + nd
found = False
for b in range(0,nb+1):
    for c in range( 0, nc+1 ):
        d = (nb + nd - c - b)
        if d%2 == 1: continue
        d = d//2
        a = n//2 - d - c - b
        if d > nd or a > na or a < 0: continue
        found = True
        break
    if found: break

if not found:
    print(-1)
else:
    ans = []
    for i in range(a):
        ans.append( none[i] )
    for i in range(b):
        ans.append( acrobats[i] )
    for i in range(c):
        ans.append( clowns[i] )
    for i in range(d):
        ans.append( both[i] )
    print(*ans)