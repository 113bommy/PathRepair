a,b,c,d=map(int,input().split())    
ta=(c+a-1)//a
ao=(b+d-1)//d

if ta<=ao:
    print("Yes")
else:
    print("No")