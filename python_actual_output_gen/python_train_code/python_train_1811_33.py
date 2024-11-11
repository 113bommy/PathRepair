T=int(input())
for t in range(T):
    l,r=map(int,input().split()) 
    if l*2<=r:
        print(l,l*2) 
    else:
        print(-1)
