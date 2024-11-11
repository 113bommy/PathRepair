from math import sqrt

n,vb,vs = map(int, input().split())
sl = list(map(int, input().split()))
xu,yu = map(int, input().split())
ans=0
t = sqrt((xu-sl[0])**2+(yu)**2)/vs
for i in range(1,n):
    _t = sqrt((xu-sl[i])**2+(yu)**2)/vs + (sl[i]-sl[i-1])/vb
    if t>=_t:
        ans=i
        t=sqrt((xu-sl[i])**2+(yu)**2)/vs
    else:
        break
if ans==0:
    ans=1
print(ans+1)


