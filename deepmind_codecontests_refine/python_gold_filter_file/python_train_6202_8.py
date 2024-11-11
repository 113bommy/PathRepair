s,x1,x2=map(int,input().split())
t1,t2=map(int,input().split())
p,d=map(int,input().split())
#歩く方が早い場合
if t1>=t2:
    print(abs(x1-x2)*t2)
    exit()
ans=abs(x1-x2)*t2
#電車に乗る場合(電車の時間)
if x1<x2:
    if d==1:
        if p<=x1:
            t=(x2-p)*t1
        elif p<x2:
            t=(2*s+(x2-p))*t1
        else:
            t=(2*s-(p-x2))*t1
    else:
        t=(p+x2)*t1
else:
    if d==-1:
        if x1<=p:
            t=(p-x2)*t1
        elif x2<p:
            t=(2*s+(p-x2))*t1
        else:
            t=(2*s-(x2-p))*t1
    else:
        t=((s-p)+(s-x2))*t1
print(min(ans,t))
