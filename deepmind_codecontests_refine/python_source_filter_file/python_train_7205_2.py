# cook your dish here
for _ in range(int(input())):
    a,b,c,n=map(int,input().split())
    t=max(a,b,c)
    if(t==a):
        an=(a-b)+(a-c)
    elif(t==b):
        an=(b-a)+(b-c)
    elif(t==c):
        an=(c-b)+(c-a)
    if((n-an)>0):
        if((n-an)%3==0):
            print("YES")
        else:
            print("NO")
    else:
        print("NO")
    
        
        