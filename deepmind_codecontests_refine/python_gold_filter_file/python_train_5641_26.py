def profit(b,f,c):
    pro = 0
    if(b>=2*f):
        pro = c*f
        b = b-2*f
    else:
        pro = b//2*c
        b = 0
    j = [b,pro]
    return j
    
for _ in range(int(input())):
    b,p,f=map(int,input().split())
    h,c = map(int,input().split())
    if(h<c):
        pro =profit(b,f,c)
        if(pro[0]==0):
            print(pro[1])
            continue
        else:
            pro1 = profit(pro[0],p,h)
            print(pro[1]+pro1[1])
    else:
        pro =profit(b,p,h)
        if(pro[0]==0):
            print(pro[1])
            continue
        else:
            pro1 = profit(pro[0],f,c)
            print(pro[1]+pro1[1])
            continue