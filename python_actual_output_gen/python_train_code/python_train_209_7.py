s=input()
t=input()
ds={}
dt={}
for i in s:
    if i in ds:ds[i]+=1
    else:ds[i]=1
for i in t:
    if i in dt:dt[i]+=1
    else:dt[i]=1
def fn(t,s,ds,dt):
    for i in t:
        if i not in ds or dt[i]>ds[i]:return 'need tree'
    if len(s)==len(t):return 'array'
    p1=0
    for i in range(len(s)):
        if s[i]==t[p1]:p1+=1
        if p1==len(t):return 'automation'
    return 'both'
print(fn(t,s,ds,dt))
