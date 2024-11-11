t=int(input())
while t:
    t-=1
    l,r=map(int,input().split())
    nas=(r+1)/2
    
    if nas>l:
        print("NO")
    else:
        print("YES")
    