t=int(input())
while t:
    a,b,c,n=map(int,input().split())
    m=max(a,b,c)
    n=n-(m-a)-(m-b)-(m-c)
    if(n%3==0 and n>=0):
        print("YES")
    else:
        print("NO")
    t-=1
    
    