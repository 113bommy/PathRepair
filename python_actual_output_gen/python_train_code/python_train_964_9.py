n=int(input())
t=list(map(int,input().split()))
y=[]
for k in range(n-2):
    y.append(t[k+1]-t[k])
p=[]
for j in range(n-2):
    o=t[j+2]-t[j]
    u = y[0:j]+y[j+2:]+[o]
    p.append(max(u))

print(min(p))


