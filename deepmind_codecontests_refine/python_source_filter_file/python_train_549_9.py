
cnt=0
vp=int(input())
vd=int(input())
t=int(input())
f=int(input())
c=int(input())

t_end=c/vp
if vp>=vd:
    print(0)
else:
    while t<t_end:
        t+=t*vp/(vd-vp)
        if t>=t_end:
            break;
        t+=f+t*vp/vd
        cnt+=1

print(cnt)
            