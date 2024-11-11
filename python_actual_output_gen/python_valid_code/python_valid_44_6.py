q=int(input())
for k in range(q):
    l,r=map(int,input().split())
    if r==l:
        print(-r if r%2==1 else r)
    else:
        if r%2==1 and l%2==0:
            print(int(-((r-l+1)/2)))
        elif r%2==0 and l%2==1:
            print(int((r-l+1)/2))
        elif r%2==1 and l%2==1:
            print("here")
            print(int((r-l)/2)+(-r if r%2==1 else r)) 
        else:
            print(int(((-(r-l)/2))+(-r if r%2==1 else r)))
