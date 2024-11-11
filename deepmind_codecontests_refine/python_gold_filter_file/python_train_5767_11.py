dir = {'N':0, 'S':0, 'E':0, 'W':0}
t,sx,sy,ex,ey = map(int, input().split())
req = {'N':0, 'S':0, 'E':0, 'W':0}
if sx>ex:
    req['W']=sx-ex
if ex>sx:
    req['E']=ex-sx
if sy>ey:
    req['S']=sy-ey
if ey>sy:
    req['N']=ey-sy
dirs=input()
left = lambda: req['N']>0 or req['S']>0 or req['W']>0 or req['E']>0
for i in range(t):
    if left():
        req[dirs[i]]-=1
    else:
        print(i)
        break
else:
    print(-1 if left() else t)
