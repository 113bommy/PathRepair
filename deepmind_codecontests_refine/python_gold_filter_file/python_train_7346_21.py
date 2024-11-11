def maxcandies(nn):
    
    final = []
    n = nn
    i = 1
    
    if n==2:
        return [2]
    
    final.append(i)
    n = n - i
    i = i + 1    
    
    while n>0:
        
        if n/2 > i:
            final.append(i)
            n = n - i
            i = i + 1
        else:
            final.append(n)
            break
    
    return final
        
        


#l = list(map(int, input().rstrip().split()))

n = int(input())

ans = maxcandies(n)

print(len(ans))
print(" ".join(str(i) for i in ans))
