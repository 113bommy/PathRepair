n=list(map(int,input().split()))
w=0
for i in range(n[0]):
    k=list(map(int,input().split()))
    t=1
    for j in range(n[0]):
        if k[t]==1 and k[t-1]==1:
            w+=1
            t+=2
            
        elif k[t]==0 and k[t-1]==1:
            w+=1
            t+=2
        elif k[t]==1 and k[t-1]==0:
            w+=1
            t+=2
        else:
            t+=2
print(w)

    