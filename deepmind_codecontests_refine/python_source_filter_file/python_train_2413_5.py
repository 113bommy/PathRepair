from sys import stdin
from bisect import bisect_left
input=stdin.readline
n,m,k,q=map(int,input().split(' '))
x=sorted(list(map(int,input().split(' ')))for i in range(k))
y=sorted(list(map(int,input().split(' '))))
def rr(c0,c1,c2):
    return abs(c2-c0)+abs(c1-c2)

def tm(c0,c1):
    t=bisect_left(y,c0)
    tt=[]
    if (t>0):
        tt.append(rr(c0,c1,y[t-1]))
    if (t<q):
        tt.append(rr(c0,c1,y[t]))
    return min(tt)

    





# thực hiện tìm xem trong một hàng, kho báu nằm từ khoảng nào đến khoảng nào.
z=[]
for r,c in x:
    if z and z[-1][0]==r:
        z[-1][2]=c
    else:
        z.append([r,c,c])
v1,v2,r0,c01,c02=0,0,1,1,1
for r1,c11,c12 in z:
    d=c12-c11+r1-r0
    # bình thường
    if(r1>r0):
        d01=tm(c01,c11)
        d02=tm(c01,c12)
        d11=tm(c02,c11)
        d12=tm(c02,c12)
        v1,v2=d+min(v1+d01,v2+d11),d +min(v1+d02,v2+d12)

    #nếu có kho báu ở hàng 1
    else:
        v1,v2=d+c12-c02,d+c11-c01
    c01,c02,r0=c11,c12,r1
ans=min(v1,v2)
print(ans)