t=  int(input())

for _ in range(t):
    n,d = map(int,input().split())
    l = list(map(int,input().split()))
    cnt=0
    for i in range(1,n):
        cnt=i
        while(l[i]>0 and d>0):
            d=d-cnt
            if(d>0):
                l[0]+=1
            l[i]-=1
        if(d<0):
            break
    print(l[0])
        
            
            
            
