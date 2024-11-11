a=list(map(int,list(input())))
b=list(map(int,list(input())))

v=list()
n=len(b)-len(a)

s=0
for i in range(n+1):
    s+=b[i]
v.append(s)

for i in range(1,len(a)):
    v.append(v[i-1]+b[n+i]-b[n+i-len(a)-1])

r=0
for i in range(len(a)):
    if a[i]==0:
        r+=v[i]
    else:
        r+=n+1-v[i]

print(r)

