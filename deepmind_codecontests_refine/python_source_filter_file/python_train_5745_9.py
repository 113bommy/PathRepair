T=int(input())
for t in range(T):
    nmk=list(map(int,input().split(" ")))
    h=list(map(int,input().split(" ")))
    i=0
    while(i<nmk[0]-1):
        
        if(h[i]>=(h[i+1]-nmk[2])):
            nmk[1]=nmk[1]+(h[i]-(h[i+1]-nmk[2]))
            i=i+1
        elif(h[i]+nmk[1]>=(h[i+1]-nmk[2])):
            nmk[1]=nmk[1]-((h[i+1]-nmk[2])-h[i])
            i=i+1
        else:
            print("NO")
            break
     
    if(i==nmk[0]-1):
        print("YES")
            
            
            
            
