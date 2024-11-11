s=[[31],[28,29],[31],[30],[31],[30],[31],[31],[30],[31],[30],[31]]
n=int(input())
l=list(map(int,input().split()))
for i in range(len(s)) :
    w=0
    poi=i
    g=True
    for j in range(n) :
        if l[j]==28 :
            w+=1
            if w>1:
                g=False
                break
        if l[j] not in s[poi] :
            g=False
            break
        poi+=1
        if poi==12 :
            poi=0
    if g :
        print("yes")
        exit()
print("no")
            
        
        
        
        
