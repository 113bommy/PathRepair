n,k,l,c,d,p,nl,np=[int(x) for x in input().split()]
jt=(k*l)//nl
lt=c*d
st=p//np
if (jt>=n) and (lt>=n) and (st>=n):
    print(min(jt,lt,st))
else:
    print(0)