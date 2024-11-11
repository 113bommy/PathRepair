t = int(input())
count = 0
ans = []
while count < t:
    dist = 0
    cor = list(map(int,input().split()))
    cor = sorted(cor)
    a,b,c = cor
    if (len(set(cor)) == 1):
        dist += 0
    elif (len(set(cor)) == 2):
        test = list(set(cor))
        if abs(test[0]-test[1]) <= 2:
            dist += 0
        else:
            dist += (abs(test[0]-test[1])-2)*2
    else:
        if (c-a <= 2):
            dist += 0
        else:
            dist += c-a-2
            if (c-1 == b):
                dist += b-a-1
            elif (c-1 > b):
                dist += c-b-2
                dist += b-a
            else:
                pass
            
    ans.append(dist)
    count += 1

for y in ans:
    print (y)


    
    
        
    
    
    
        
    

        
    
        
