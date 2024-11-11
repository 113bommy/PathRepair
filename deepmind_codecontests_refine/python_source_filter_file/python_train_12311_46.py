# cook your dish here
t=int(input())
for _ in range(t):
    a,b,c=map(int,input().split())
    if a>=c:
        k=-1
    else:
        k=1
    x=a*b
    if x>c:
        m=a
    else:
        m=-1
    print(k,m)

    
        
    