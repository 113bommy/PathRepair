# できなかった
# アームの長さが決まると(xm+ym)mod2は一定になる、これが一定でなければ無理
# (xj+yj)mod2=1としてよい、長さ1の腕を追加することで0の場合も考えられる
# (u,v)=(x+y,x-y)(回転座標)とすると、ui,viをu(i+1),v(i+1)から独立に決定できる(+d,-dいづれかはされることが確定している)
# よってdiを決めたときにui,viを決める問題をu,vについて独立に解けば、各関節の向きを決定できる
# u(i+1)=ui+diとなるi∈{1,...,m}の集合をSとすると、u(m)=-Σ(1≦i≦m) di +Σ(i∈S) 2di が成り立つ
# -2*10^9≦Uj,Vj≦2*10^9 と 1≦m≦40 より m=31,di=2^(i-1) とできる。すると、Uj=-(2^31-1) +Σ(i∈S) 2di となる
# つまりΣ(i∈S) 2di =Uj+(2^31-1) となるようにSを選ぶことができるので解ける
n=int(input())
listXY=[list(map(int,input().split())) for _ in range(n)]
listUV=[[listXY[i][0]+listXY[i][1],listXY[i][0]-listXY[i][1]]for i in range(n)]

isOdd=listUV[0][0]%2
canReach=1
for i in range(1,n):
    if isOdd!=listUV[i][0]%2:
        canReach=0
        break

if not canReach:
    print(-1)
else:
    offset=2**31-isOdd
    m=32-isOdd
    d=[2**i for i in range(32)]
    w=[]
    for i in range(n):
        x,y=0,0
        u,v=listUV[i][0]+offset,listUV[i][1]+offset
        s=''
        if not isOdd:
            s='D'
            y=y-1
        for k in range(31):
            u //= 2
            v //= 2
            u1, v1 = u % 2, v % 2
            # L(-d,-d),R(+d,+d),D(-d,+d),U(+d,-d)
            if u1 == 0 and v1 == 1:
                s += 'D'
                y=y-d[k]
            elif u1 == 0 and v1 == 0:
                s += 'L'
                x=x-d[k]
            elif u1 == 1 and v1 == 1:
                s += 'R'
                x=x+d[k]
            elif u1 == 1 and v1 == 0:
                s += 'U'
                y=y+d[k]
        w.append(s)
        # print(x,y,s)
    # print(listXY)
    # print(listUV)
    print(32-isOdd)
    s=''
    if not isOdd:
        s='1 '
    for i in range(32):
        s+=str(d[i])+' '
    print(s)
    for i in range(n):
        print(w[i])
