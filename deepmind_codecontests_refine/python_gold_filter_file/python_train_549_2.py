vp=int(input())
vd=int(input())
t=int(input())
f=int(input())
c=int(input())
dp=vp*t
dd=0
cout=0
#print(dp)
if vp>=vd:
    print(cout)
else:
    while dp<c:
        x=(dp-dd)/(vd-vp)
        dp+=vp*x
    #    print(dp)
        if dp>=c:
            break
        cout+=1
        dd=vd*x
        x=dd/vd +f
        dp+=vp*x
        dd=0
    #    print(dp)
    print(cout)
