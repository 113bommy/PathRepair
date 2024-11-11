for _ in range(int(input())):
    a,b=map(int,input().split())
    x=abs(b-a)
    res=0
    if x>5:
        res+=x//5
        
    if x%5>2:
        res+=2
    elif x%5!=0:
        res+=1
    print(res)
        

    
