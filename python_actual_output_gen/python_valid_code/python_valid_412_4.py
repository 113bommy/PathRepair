n,a,b=map(int,input().split())
mp=int((a+b)/n)
while True:
    if a//mp+b//mp<n:
        mp-=1
    else:
        print(mp)
        break
    
