
for _ in range(int(input())):
    n = int(input())
    
    c2,c3 = 0,0
    while(n%2):
        n/=2
        c2+=1
        
    while(n%3):
        n/=3
        c3+=1
    
    if(n==1 and c2<=c3):
        print(c3-c2 + c3)
    else:
        print(-1)