while 1:
    n=int(input())
    if not n:break    
    t=0
    cnt=0
    for i in range(2,n+1):
        o=n//i
        t+=(i-1) 
        p=n-(i*o-t)
        if o+p//i+1-i<1:break
        if p%i==0:cnt+=1
    print cnt

