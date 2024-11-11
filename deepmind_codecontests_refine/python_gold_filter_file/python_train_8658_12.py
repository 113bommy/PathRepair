if __name__ == '__main__': 
    n,l,r=map(int,input().split())
    #print(n,l,r)
    mn=1
    cnt=1
    i=2
    while True:
        if(cnt>=l):
            break
        mn=mn+i
        i=i*2
        cnt=cnt+1
    mn=mn+(n-l)
    mx=1
    cnt=1
    m=1
    i=2
    while True:
        if(cnt>=r):
            break
        mx=mx+i
        
        cnt=cnt+1
        if i>m:
            m=i
        i=i*2  
    mx=mx+(n-r)*m
    print(mn,mx)
        
        