def solve(n,k,seq) :
    ans = []
    for outerIndex in range(n-1) :
        maxAllowed = seq[outerIndex] + k
        for innerIndex in range(n) :
            if maxAllowed < seq[innerIndex] :
                print ("NO")
                return

    for i in seq :
        temp = []
        start = 1
        if i > k :
            end = k + 1
            remainder = i%k
            if remainder > 0 :
                temp.extend(list(range(1,remainder+1)))
            elif i//k > 1 :
                theList = list(range(start,end))
                for _ in range(1,i//k) :
                    temp.extend(theList)    
        else :
            end = i + 1
        temp.extend(list(range(start,end)))
        ans.append(temp)
            
                
    print ("YES")
    for arr in ans :
        for ele in arr :
            print (ele,end = " ")
        print (" ")
        

n,k = list(map(int,input().split()))
seq = list(map(int,input().split()))
solve(n,k,seq)
                
                
                
    