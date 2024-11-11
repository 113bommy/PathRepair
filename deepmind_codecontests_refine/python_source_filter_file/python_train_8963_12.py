a =int(input())
v=0
s=0
d=dict()
for i in range(a):
    b,r =input().split()
    if b == "R":
        v=v+1
        d[r]=v
    elif b == "L":
        s=s-1
        d[r]=s
    else:
        print(min(v-d[r],d[r]-s))
        
