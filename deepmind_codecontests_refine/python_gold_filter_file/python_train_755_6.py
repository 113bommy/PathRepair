
t = int(input())
   
for caseNr in range(1, t + 1):
    n = int(input())
    array = list(map(int, input().split()))
    
    max_ = max(array)
    
    candidate = None
    for i,elmt in enumerate(array):
        #print(i)
        if elmt == max_:
            if (i!=0 and array[i-1] < elmt):
                candidate = i
                break
            if (i != len(array)-1 and array[i+1]<elmt):
                candidate = i
                break
                
        #print("DONE")
    
    if candidate == None:
        print(-1)
    else:
        print(candidate+1)