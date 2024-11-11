N,*f = map(int, open(0).read().split())
xy = [f[i*2:i*2+2] for i in range(N)]
s = [sum(z) for z in xy]
a = max(s) - min(s)
t = [abs(z[0]-z[1]) for z in xy]
b = max(t) - min(t)
print(max(a,b))