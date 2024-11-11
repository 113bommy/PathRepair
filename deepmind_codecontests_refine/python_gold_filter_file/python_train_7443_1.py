from fractions import gcd
n = int(input())
a = sorted(list(map(int,input().split())))[::-1]
c = {}
l = []

for e in a:
    if(e not in c):
        c[e]=1
    else:
        c[e]+=1

for e in a:
    while(n>0 and c[e]>0):
        c[e]-= 1
        for s in l:
            u=gcd(e,s)
            if(u in c):
                c[u]-= 2
        l+=[e]
print(*l)