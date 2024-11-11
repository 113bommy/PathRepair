a=int(input())
b=int(input())
c=input().split()
d=input().split()
s=10**9
last=0
while True:
    t=s
    lasts=s
    for i in range(a):
        t=t-(b+t)/int(d[i])
        t=t-(b+t)/int(c[i])
    if t<0:
        lasst=s
        s=s+(s-last)/2
        last=lasst
        
    else:
        s=(s+last)/2
    if s==lasts:
        if s>=10**9:
            print(-1)
        else:
            print(s)
        break

