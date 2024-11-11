n,t = map(int,input().split())
data = list(map(int,input().split()))
i=0
while i<len(data):
    if (data[i]+i+1)==t:
        print("YES")
        
        break
    elif (data[i]+i+1)<t:
        i=data[i]+i
    else:
        print("NO")
        break
        
        
    
    