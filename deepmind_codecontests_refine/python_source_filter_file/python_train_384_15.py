

n = int(input())


t = list(map(int,input().split()))


u=0
v=0

e=2
o=1
for j in t:
    u+=abs(e-j)
    v+=abs(o-j)
    o+=2
    e+=2

print(min(v,u))
