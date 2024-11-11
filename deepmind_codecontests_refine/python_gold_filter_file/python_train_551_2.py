import sys
input=sys.stdin.readline
n=int(input())
a=[]
b=0
for _ in range(n):
    c,d=map(int,input().split())
    a.append((c,d))
    b+=c
a.sort(key=lambda x:x[1])
aa=[a[0]]
for i in range(1,n):
    if a[i][1]==a[i-1][1]:
        aa[-1]=(aa[-1][0]+a[i][0],a[i][1])
    else:
        aa.append(a[i])
e=0
f=0
for i in range(n):
    if a[i][1]<=e:
        e+=a[i][0]
        f+=a[i][0]
        if e>b:
            f-=(e-b)
            break
    else:
        if a[i][1]<b:
            f+=(a[i][1]-e)*2
            e+=a[i][1]-e
            if e>b:
                f-=(e-b)*2
                break
            e+=a[i][0]
            f+=a[i][0]
            if e>b:
                f-=(e-b)
                break
        else:
            f+=a[i][0]*2
            e+=a[i][0]
            if e>b:
                f-=(e-b)*2
                break
print(f)