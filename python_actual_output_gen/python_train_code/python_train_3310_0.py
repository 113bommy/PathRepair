for i in range(int(input())):
    a,b,c,d=map(int,input().split())
    e=a-b
    if e<1:
        print(b)
        continue
    else:
        if c-d<1:
            print(-1)
            continue
        else:
            f=int(e//(c-d))
            if b+f*d>=a:
                print(b+f*c)
            else:
                print(b+(f+1)*c)
        
        
        
