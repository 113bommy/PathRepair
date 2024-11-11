t = int(input()) 
for i in range(t): 
    [a,b] = input().split() 
    a=int(a) 
    b=int(b) 
    c=max(a,b) 
    d=min(a,b) 
    if(c==d): 
        print("0 0") 
    else: 
        temp1 = c-d 
        temp2 = min(c%(c-d),(c-d-1)-(c%(c-d))) 
        print(f"{temp1} {temp2}") 

    