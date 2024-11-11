for _ in range(int(input())):
    c1,c2,c3=map(int ,input().split())
    a1,a2,a3,a4,a5=map(int ,input().split())
    c1-=a1
    c2-=a2
    c3-=a3
    if(min(c1,c2,c3)<0):
        print("NO")
    else:
        if(c2+c3>=a5):
            x=min(a5,c2)
            c2-=x
            a5-=x
            c3=c3-a5+x
            if(c1+c3>=a4):
                print("YES")
            else:
                print("NO")
        else:
            print("NO")