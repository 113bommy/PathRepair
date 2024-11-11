n=int(input())
coos=[]
pref=[]
x1,y1,x2,y2=map(int,input().split())
coos.append([x1,y1,x2,y2])
pref.append([x1,y1,x2,y2])

def intersect(coo1,coo2):
    if not coo1 or not coo2:
        return False
    x_left=max(coo1[0],coo2[0])
    x_right=min(coo1[2],coo2[2])
    y_down=max(coo1[1],coo2[1])
    y_up=min(coo1[3],coo2[3])
    if x_left>x_right or y_down>y_up:
        return False
    else:
        return [x_left,y_down,x_right,y_up]
for i in range(n-1):
    x1,y1,x2,y2=map(int,input().split())
    coos.append([x1,y1,x2,y2])
    pref.append(intersect(coos[-1],pref[-1]))

suf=[coos[-1]]
for i in range(n-2,-1,-1):
    suf.append(intersect(suf[-1],coos[i]))
suf=suf[::-1]

if suf[1]:
    print(suf[1][0],suf[1][1])
elif pref[n-2]:
    print(pref[n-2][0],pref[n-2][1])
else:
    for i in range(2,n-1):
        sth=intersect(pref[i-1],suf[i+1])
        if sth:
            print(sth[0],sth[1])
            exit(0)

