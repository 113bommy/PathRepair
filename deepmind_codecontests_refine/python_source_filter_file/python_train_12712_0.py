def g(a):
    return((a[0],-a[1]))
n=int(input())
r=list(map(int,input().split()))
partials=[]
sumi=0
for i in range(n):
    sumi+=r[i]-100
    partials.append((sumi,i))
partials.append((0,-1))
partials.sort(key=g)
mini=n
long=0
for i in range(n):
    if partials[i][1]<mini:
        mini=partials[i][1]
    else:
        long=max(long,partials[i][1]-mini)
print(long)