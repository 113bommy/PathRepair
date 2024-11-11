u,v=map(int,input().split())
if u>v or abs(u-v)%2:
    print(-1)
elif u==0 and v:
    if v%2:
        print(-1)
    else:
        print(2)
        print(v//2,v//2)
elif u==v and u!=0:
    print(1)
    print(u)
elif u==v==0:
    print(0)
else:
    d=abs(v-u)//2
    if u^(d*2):
        print(3)
        print(u,d,d)
    else:
        print(2)
        print(u+d,d)

    