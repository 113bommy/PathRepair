i=input
n,m=map(int,i().split())
d=dict([i().split()[::-1] for _ in[0]*n])
for _ in[0]*m:a=i();print(a,'# '+d[a.split()[1][:-1]])