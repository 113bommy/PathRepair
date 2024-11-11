for t in range(int(input())):
    def sumSquare(n): 
  
        s = dict() 
        for i in range(n): 
      
            if i * i * i> n: 
                break
      
            # store square value in hashmap 
            s[i * i *i] = 1
      
            if (n - i * i * i) in s.keys(): 
                
                return True
              
        return False
      
    # Driver Code 
    n = int(input())
    if (sumSquare(n)): 
        print("Yes") 
    else: 
        print("No") 
