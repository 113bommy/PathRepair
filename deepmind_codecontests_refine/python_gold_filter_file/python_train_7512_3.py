n,r = map(int,input().split())
l = list(map(int,input().split()))
g = []
for i in range(1,n):
    g.append(l[i]-l[i-1])
g.sort()
print(sum(g[:n-r]))
