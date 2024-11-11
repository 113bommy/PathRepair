
def func(u,v,a,l):
    if (v**2-u**2)>=2*a*l:
        return ((u**2+2*a*l)**(1/2)-u)/a
    else:
        t1=(v-u)/a
        t2=(l-(u*t1+a*t1*t1/2))/v
        return t1+t2
def efficient(v,a,w,d):
    if 2*v*v-w*w<=2*a*d:
        t1=v/a
        t2=(v-w)/a
        t3=(d-0.5*a*t1*t1-v*t2+0.5*a*t2*t2)/v
        return t1+t2+t3
    else:
        bound=((2*a*d+w*w)/2)**0.5
        t1=bound/a
        t2=(bound-w)/a
        t3=func(0,w,a,d)
        return t1+t2
        return min(t1+t2,t3)
def main():
    string1=input()
    string2=input()
    arr1=string1.split(" ")
    arr2=string2.split(" ")
    a=int(arr1[0])
    v=int(arr1[1])
    l=int(arr2[0])
    d=int(arr2[1])
    w=int(arr2[2])
    if 2*a*d<=w**2:
        t1=func(0,v,a,l)
        print("%.8f"%(t1))
    else:
        t1=efficient(v,a,w,d)
        t2=func(w,v,a,l-d)
        print("%.8f"%(t1+t2))
main()
