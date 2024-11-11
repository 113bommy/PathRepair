t=int(input())
for k in range(t):
    x,y=map(int,input().split())
    l1=list(map(int,input().split()))
    l2=list(map(int,input().split()))
    l3=list(map(int,input().split()))
    l4=list(map(int,input().split()))
    m1=(l1[-1]-l1[1])*y
    m2=(l2[-1]-l2[1])*y
    m3=(l3[-1]-l3[1])*x
    m4=(l4[-1]-l4[1])*x
    res=max([m1,m2,m3,m4])
    print(res/1)