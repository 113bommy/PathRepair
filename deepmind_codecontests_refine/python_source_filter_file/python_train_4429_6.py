n,c=map(int,input().split())
l=list(map(int,input().split()))
t=list(map(int,input().split()))
u=t[::-1]
for i in range(1,n):
    t[i],u[i]=t[i]+t[i-1],u[i]+u[i-1]
pl=0
ql=0
for i in range(n):
    if l[i]>=c*(t[i]):
        pl+=t[i]*c
    else:
        pl+=l[i]
    if l[n-1-i]>=c*(u[i]):
        ql+=u[i]*c
    else:
        ql+=l[n-1-i]
if pl<ql:
    print('Limak')
elif pl>ql:
    print('Rashwood')
else:
    print('Tie')
