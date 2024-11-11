t=int(input())
for _ in range(t):
    n=int(input())
    aaa=list(map(int,input().split()))
    aaa.sort()
    go=True
    s=0
    b=aaa[0]
    bm=b
    for j in range (1,n):
        s-=aaa[j-1]
        #print(j,aaa[j],s,b)
        if aaa[j]+s >bm : bm=aaa[j]
        #print(j,s,b,bm)
        
    
    
    print(bm)
