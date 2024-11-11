q=int(input().strip())
for i in range(q):
    a,b,m=map(int,input().strip().split())
    p=a+1
    q=a+m
    c=1
    pos=0
    q=0
    if(b==a):
        print(1,a)
    else:
        while(b/c>a+m):
            c=c<<1
            q+=1
        if(b/c>=a+1):
            pos=1
        if(pos):
            #print(b,c)
            d=(c*(a))
            l=[1 for i in range(q+1)]
            ll=[ii-1 for ii in range(q+1)]
            ll[0]+=1
            s=b-d-c
            pp=q
            #print(s,pp)
            while(s>0):
                l[pp]+=(s//pow(2,ll[pp]))
                s=s-((l[pp]-1)*pow(2,ll[pp]))
                pp-=1
            ss=a
            po=a
           # print(l)
            print(q+2,end=" ")
            print(ss,end=" ")
            for i in range(q+1):
                ss=po+l[q-i]
                print(ss,end=" ")
                po=po+ss
            print()

        else:
            print(-1)