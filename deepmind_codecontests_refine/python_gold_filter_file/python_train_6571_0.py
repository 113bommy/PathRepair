#      
import collections, atexit, math, sys, bisect 

sys.setrecursionlimit(1000000)
def getIntList():
    return list(map(int, input().split()))    

try :
    #raise ModuleNotFoundError
    import numpy
    def dprint(*args, **kwargs):
        #print(*args, **kwargs, file=sys.stderr)
        # in python 3.4 **kwargs is invalid???
        print(*args,  file=sys.stderr)
    dprint('debug mode')
except Exception:
    def dprint(*args, **kwargs):
        pass



inId = 0
outId = 0
if inId>0:
    dprint('use input', inId)
    sys.stdin = open('input'+ str(inId) + '.txt', 'r') #标准输出重定向至文件
if outId>0:
    dprint('use output', outId)
    sys.stdout = open('stdout'+ str(outId) + '.txt', 'w') #标准输出重定向至文件
    atexit.register(lambda :sys.stdout.close())     #idle 中不会执行 atexit
    
p0 = getIntList()
p1 = getIntList()
p2 = getIntList()
#print(N)

zp = [p0, p1, p2]



def getpath( p0, p1):
    if p0[0] < p1[0]:
        sp = 1
    elif p0[0] > p1[0]:
        sp = -1
    else:
        sp =0
    zz = [tuple(p0), tuple(p1)]
    if sp!=0:
        for x in range(p0[0], p1[0]+ sp, sp):
            tp = (x, p0[1])
            zz.append(tp)
    if p0[1] < p1[1]:
        sp = 1
    elif p0[1] > p1[1]:
        sp = -1
    else:
        sp = 0
    if sp!=0:
        for y in range(p0[1], p1[1] + sp, sp):
            tp = (p1[0], y)
            zz.append(tp)
    return zz

nr = 1000000;
zr = set()
for i in range(3):
    for j in range(3):
        cx = zp[i][0]
        cy = zp[j][1]
        cp = (cx, cy)
        z1 = getpath(cp, zp[0])
        z2 =getpath(cp, zp[1])
        z3 =getpath(cp, zp[2])
        
        z0 = z1+z2+z3
        s1 = set(z0)
        dprint(cp,s1)
        if len(s1) < nr:
            nr = len(s1)
            zr = s1
        
print(len(zr))
for x in zr:
    print(x[0], x[1])



