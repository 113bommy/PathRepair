q=int(input())
for _ in range(q):
    k,n,a,b=map(int,input().split())
    r=n*b
    diff=k-r
    if(diff<=0):
        print(-1)
        continue
    else:
        if((diff-1)//(a-b)<=5):
            print((diff-1)//(a-b))
        else:
            print(n)
    
