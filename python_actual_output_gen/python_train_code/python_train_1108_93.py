def check(a,b):
    
    if(a==1 and b==1):
        return 1
    c=0
    while(a<b):
        a=a*3
        b=b*2
        c+=1 
        if(a==b):
            c+=1
    return c
a,b=map(int,input().split())

ans=check(a,b)
print(ans)