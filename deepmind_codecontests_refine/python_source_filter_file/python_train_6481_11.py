t=input()
t=int(t)

while(t>0):
    n = int(input())
    a = list(map(int,input().strip().split()))[:n] 

    first=True
    cnt=0
    for i in a:
        if(i==1):
            cnt+=1
        else:
            break
    
    if(cnt==n):
        if(n%2==0):
            first = False
        else:
            first = True
    
    else:       
        if(cnt==0 or cnt%2==0):
            first=True
        else:
            first=False
    
    if(first):
        print("FIRST")
    else:
        print("SECOND")
    
    t-=1