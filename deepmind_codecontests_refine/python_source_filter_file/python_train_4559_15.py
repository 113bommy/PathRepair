a,b,m = map(int,input().split())
a = list(map(int,input().split()))
b = list(map(int,input().split()))
c = [tuple(map(int,input().split())) for i in range(m)]
p = [min(a)+min(b)]
for t in c:
    p.append((p,a[t[0]-1]+b[t[1]-1]-t[2])
print(min(p))