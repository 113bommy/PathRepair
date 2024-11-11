for _ in range(int(input())):
    n,c0,c1,h=map(int,input().split())
    s=input()
    cnt_z=s.count("0")
    cnt_o=s.count("1")
    cost1=0
    cost2=0
    cost1=(cnt_z*c0)+(cnt_o*c1)
    if c0<=c1:
        cost2=c0*n+cnt_o*h
    elif c1>c0:
        cost2=c1*n+cnt_z*h
    if cost2==0:
        print(cost1)
    else:
        print(min(cost1,cost2))
