def solve(n,seq) :
    ans = 0
    temp = 1
    index = 0
    innerIndex = 0
    
    while index < n-1 :
        temp = 1
        innerIndex = index + 1
        while innerIndex < n :
            if seq[index] == seq[innerIndex] :
                temp += 1
            innerIndex += 1
        
        if temp > ans :
            ans = temp
        index += 1
    
    if temp > ans :
        ans = temp
    

    return ans
    
    
n = int(input())
seq = []
for x in range(n) :
    seq.append(input())

print (solve(n,seq))
    
        
    
   