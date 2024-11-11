a,v=map(int,input().split())
l,d,w=map(int,input().split())
t=0
def gett(a,b,c):
    delta=b**2-4*a*c
    t1=(-b+delta**(1/2))/(2*a)
    t2=(-b-delta**(1/2))/(2*a)
    if min(t1,t2)>0:
        return min(t1,t2)
    else:
        return max(t1,t2)
if 2*a*d<=w*w or v<=w:
    if 2*a*l<=v*v:
        t=(2*l/a)**(1/2)
    else:
        t=l/v+v/a/2
else:
    tmp=d-1/2*v*v/a+1/2*(v-w)**2/a-v*(v-w)/a
    if tmp<=0:
        tmp2=l-d-(1/2*(v-w)**2/a+v*(v-w)/a)
        if tmp2>=0:
            t=tmp2/v+(v-w)/a+2*gett(a,2*w,w*w/(2*a)-d)+w/a
        else:
            t=gett(a/2,w,d-l)+2*gett(a,2*w,w*w/(2*a)-d)+w/a
    else:
        tmp2=l-d-(1/2*(v-w)**2/a+v*(v-w)/a)
        if tmp2>=0:
            t=tmp2/v+(v-w)/a+(2*v-w)/a+tmp/v
        else:
            t=gett(a/2,w,d-l)+(2*v-w)/a+tmp/v
print("%.12f" %(t))
