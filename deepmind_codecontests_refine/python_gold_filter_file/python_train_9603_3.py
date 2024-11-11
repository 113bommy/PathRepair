n=int(input())

for i in range(n):
    l=list(map(int, input().split()))
    
    if l[0]<=l[1]:
        print(l[1])
        
    else:
        hrs=l[1]
        rem=l[0]-l[1]
        sleep=l[2]-l[3]
        if sleep<=0:
            print(-1)
            
        else:
            x=rem/sleep
            y=0
            if x.is_integer():
                y=int(x)
            else:
                y=int(x)+1
                    
                
            print(hrs+(l[2]*y))