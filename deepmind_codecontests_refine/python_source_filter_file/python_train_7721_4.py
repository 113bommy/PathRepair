def mostFrequent(arr, n): 
  
    # Sort the array 
    arr.sort() 
  
    # find the max frequency using 
    # linear traversal 
    max_count = 1; res = arr[0]; curr_count = 1
      
    for i in range(1, n):  
        if (arr[i] == arr[i - 1]): 
            curr_count += 1
              
        else : 
            if (curr_count > max_count):  
                max_count = curr_count 
                res = arr[i - 1] 
              
            curr_count = 1
      
    # If last element is most frequent 
    if (curr_count > max_count): 
      
        max_count = curr_count 
        res = arr[n - 1] 
      
    return res 
    
a=list(map(int,input().split()))
b=[]
for i in range(a[0]):
    b.append(input())
 
 
c=list(map(int,input().split()))


score=0
for i in range(a[1]):
    templist=[]
    for j in range(a[0]):
        templist.append(b[j][i])
    n=len(templist)
    maxop=mostFrequent(templist,n)
    print(maxop,templist)
    countop=templist.count(maxop)
    score=score+(countop*c[i])
print(score)