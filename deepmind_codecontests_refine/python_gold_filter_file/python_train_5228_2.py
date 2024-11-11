w=int(input())
for _ in range(w):
    c,s=list(map(int,input().split()))
    n=int(c/s)
    r=c-(n*s)
    rs=int(s/2)
    
    if r<rs:
        sol=(n*s)+r
    else:
        sol=(n*s)+rs
    print(sol)