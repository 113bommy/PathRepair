n=int(input())
for i in range(n):
    l,r=map(int,input().split())
    m=r//2
    if r%2: 
        m-=r
    l-=1
    t=l//2
    if l%2: t-=l
    print(m+t)
    
