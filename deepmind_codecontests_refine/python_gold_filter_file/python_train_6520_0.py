import sys, math
def dist(a,b):
    return pow((a[0] - b[0])**2 + (a[1] - b[1])**2 + (a[2] - b[2])**2,0.5)

def vxv(v1,v2):
    x = -v1[2] * v2[1] + v1[1] * v2[2]
    y = -v1[0] * v2[2] + v1[2] * v2[0]
    z = -v1[1] * v2[0] + v1[0] * v2[1]
    return (x,y,z)
readline = sys.stdin.readline
s1,s2,s3,v1,v2,v3,R = map(int,readline().split())
n = int(readline())
pm = []
p = []

for _ in range(n):
    o1,o2,o3,r,m = map(int,readline().split())
    p.append((o1,o2,o3,r))
    for _ in range(m):
        pm1,pm2,pm3 = map(int,readline().split())
        pm.append((pm1 + o1, pm2 + o2, pm3 + o3))

nv = (v1,v2,v3)
m = (s1,s2,s3)
distance = []
for x in pm:
    tp = (x[0] - m[0], x[1] - m[1], x[2] - m[2])
    tp1 = vxv(tp,nv)
    d = dist(tp1,(0,0,0))/dist(nv,(0,0,0))
    if d <= R:
        dd = pow(dist(x,m)**2-d**2,0.5)
        dnv = dist(nv, (0, 0, 0))
        nnv = (dd * nv[0] / dnv + m[0], dd * nv[1] / dnv + m[1], dd * nv[2] / dnv + m[2])
        if dist(nnv, x) < dist(x, m):
            distance.append(dd - pow(R**2 - d**2,0.5))
for i in range(len(p)):
    pi =(p[i][0],p[i][1],p[i][2])
    tp = (pi[0] - m[0], pi[1] - m[1], pi[2] - m[2])
    tp1 = vxv(tp,nv)
    d = dist(tp1,(0,0,0))/dist(nv,(0,0,0))
    if d - p[i][3] <= R:
        dd = pow(dist(pi,m)**2-d**2,0.5)
        dnv = dist(nv,(0,0,0))
        nnv = (dd * nv[0]/dnv + m[0], dd * nv[1]/dnv + m[1],dd * nv[2]/dnv + m[2])
        if dist(nnv,p[i]) < dist(p[i],m):
            dr = pow((R + p[i][3])**2 - d**2,0.5)
            distance.append(dd - dr)


if len(distance):
    distance.sort()
    print(distance[0]/dist(nv,(0,0,0)))
else:
    print(-1)
