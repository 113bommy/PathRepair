for i in range(int(input())):
    a,b=list(map(int,input().split()))
    c=list(map(int,input().split()))
    c.sort()
    c=c[::-1]
    if(sum(c)<b):
        print(0)
    else:
        d=0
        e=1
        f=0
        for i in range(a):
            d+=c[i]
            if((d/e)<b):
                break
            else:
                e+=1
                f+=1
    print(f)