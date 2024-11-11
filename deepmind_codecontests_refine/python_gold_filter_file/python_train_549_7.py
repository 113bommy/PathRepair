import sys

vp = int(sys.stdin.readline())  # speed of princess
vd = int(sys.stdin.readline())  # speed of dragon
t = int(sys.stdin.readline())   # discovery time
f = int(sys.stdin.readline())   # adjust time
c = int(sys.stdin.readline())   # distance

totalTime = c/vp-t
sp = t*vp

b = 0
if vp < vd:
    while totalTime > 0:
        totalTime -= sp/(vd-vp)
        if totalTime>0:
            sp += vp * sp/(vd-vp)
            totalTime -= f + sp/vd
            sp += (f + sp/vd) * vp
            b+=1
        else:
            break
print(b)
